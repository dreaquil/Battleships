//
// Created by david on 02/11/2020.
//

#include <vector>
#include <mutex>
#include <algorithm>
#include "SessionManager.hpp"
#include "buisness-logic/PlayerData.hpp"

#include "dto/AddPlayerDto.hpp"
#include "dto/PlayerShipPositionsDto.hpp"

namespace
{
    std::mutex mainMutex;


    Battleships::SessionManager::GuessResponse translateGuessResponse(Battleships::GameplayController::GuessResponse gameRsp) {
        using namespace Battleships;
        switch (gameRsp) {
            case GameplayController::GuessResponse::ACCEPTED_HIT_AND_SUNK :
                return SessionManager::GuessResponse::ACCEPTED_HIT_AND_SUNK;
            case GameplayController::GuessResponse::ACCEPTED_HIT :
                return SessionManager::GuessResponse::ACCEPTED_HIT;
            case GameplayController::GuessResponse::ACCEPTED_HIT_AND_SUNK_WIN_CONDITION :
                return SessionManager::GuessResponse::ACCEPTED_HIT_AND_SUNK_WIN_CONDITION;
            case GameplayController::GuessResponse::ACCEPTED_MISS :
                return SessionManager::GuessResponse::ACCEPTED_MISS;
            case GameplayController::GuessResponse::REJECTED_INVALID_COORDINATE :
                return SessionManager::GuessResponse::REJECTED_INVALID_COORDINATE;
            default:
                return SessionManager::GuessResponse::UNSPECIFIED_ERROR;
        }
    }
}

namespace Battleships {


    SessionManager::AddPlayerResponse SessionManager::addPlayer(const AddPlayerDto &dto) {
        const std::lock_guard<std::mutex> lock(mainMutex);

        switch (_state) {
            case GameState::WAITING_FOR_PLAYER : {

                switch (nPlayers()) {
                    case 0 : {
                        players.emplace_back(dto);
                        return AddPlayerResponse::ACCEPTED_JOINED_SESSION_AS_PLAYER_1;
                    }
                    case 1 : {
                        _state = GameState::PLACING_SHIPS;
                        players.emplace_back(dto);
                        return AddPlayerResponse::ACCEPTED_JOINED_SESSION_AS_PLAYER_2;
                    }
                    default : {
                        return AddPlayerResponse::UNSPECIFIED_ERROR;
                    }
                }
            }
            default : {
                return AddPlayerResponse::REJECTED_SESSION_IN_PROGRESS;
            }
        }
    }


    SessionManager::ShipPlacementResponse SessionManager::placeShips(const PlayerShipPositionsDto &dto) {
        const std::lock_guard<std::mutex> lock(mainMutex);

        int iPlayer = dto.id;

        switch (_state){
            case GameState::PLACING_SHIPS : {

                if (iPlayer>=nPlayers()) return ShipPlacementResponse::UNSPECIFIED_ERROR;

                PlayerShipStore shipsLayout(dto);
                if (!shipsLayout.isValid()) return ShipPlacementResponse::REJECTED_INVALID_LAYOUT;

                switch (iPlayer){
                    case 0 : {
                        _gameplayController.positionPlayer1Ships(dto);
                        if (!_gameplayController.isPlayer2Setup())
                            return ShipPlacementResponse::ACCEPTED_UPDATED_SHIP_POSITIONS_WAITING_FOR_OTHER_PLAYER;
                        break;
                    }
                    case 1 : {
                        _gameplayController.positionPlayer2Ships(dto);
                        if (!_gameplayController.isPlayer1Setup())
                            return ShipPlacementResponse::ACCEPTED_UPDATED_SHIP_POSITIONS_WAITING_FOR_OTHER_PLAYER;
                        break;
                    }
                    default :
                        return ShipPlacementResponse::UNSPECIFIED_ERROR;

                }

                _state = GameState::PLAYER_1_TURN;

                return ShipPlacementResponse::ACCEPTED_UPDATED_SHIP_POSITIONS_GAME_STARTING;
            }
            default : {
                return ShipPlacementResponse::REJECTED_CANNOT_PLACE_SHIPS_NOW;
            };
        }
    }


    SessionManager::GuessResponse SessionManager::playerGuess(const PlayerGuessDto &dto) {
        const std::lock_guard<std::mutex> lock(mainMutex);

        int id = dto.id;
        if (id<0 || id<2 || id>=players.size()) return SessionManager::GuessResponse::REJECTED_UNRECOGNISED_PLAYER;
        if (id==0 && _state != GameState::PLAYER_1_TURN)  return SessionManager::GuessResponse::REJECTED_USER_CANNOT_GUESS_NOW;
        if (id==1 && _state != GameState::PLAYER_2_TURN)  return SessionManager::GuessResponse::REJECTED_USER_CANNOT_GUESS_NOW;

        // figure out annoying cast...
        int iRow = dto.iRow;
        int iCol = dto.iColumn;
        Row row = Row(iRow);
        Column column = Column(iCol);

        Coordinate coord(Row(iRow),column);
        GameplayController::GuessResponse gameResponse = (id == 0) && (id != 1) ?
                                                         _gameplayController.handlePlayer1Guess(coord) :
                                                         _gameplayController.handlePlayer2Guess(coord);

        switch (gameResponse) {
            case GameplayController::GuessResponse::ACCEPTED_HIT :
            case GameplayController::GuessResponse::ACCEPTED_HIT_AND_SUNK :
            case GameplayController::GuessResponse::ACCEPTED_MISS :
            {
                if (_state == GameState::PLAYER_1_TURN) _state = GameState::PLAYER_2_TURN;
                if (_state == GameState::PLAYER_2_TURN) _state = GameState::PLAYER_1_TURN;
                break;  // change turns...
            }
            case GameplayController::GuessResponse::ACCEPTED_HIT_AND_SUNK_WIN_CONDITION :
            {
                _state = GameState::WAITING_FOR_PLAYER;
                break; // restart again...
            }
            case GameplayController::GuessResponse::REJECTED_INVALID_COORDINATE :
            case GameplayController::GuessResponse::REJECTED_UNRECOGNISED_PLAYER :
            case GameplayController::GuessResponse::REJECTED_USER_CANNOT_GUESS_NOW :
            {
                break; // error | same player gets a go...
            }

        }

        return translateGuessResponse(gameResponse);
    }

    SessionManager::RestartResponse SessionManager::restartGame(const GameRestartDto &dto) {
        const std::lock_guard<std::mutex> lock(mainMutex);

        int id = dto.id;
        if (id<0 || id<2 || id>=players.size()) return SessionManager::RestartResponse::REJECTED_UNRECOGNISED_PLAYER;

        players.clear();
        _state = GameState::WAITING_FOR_PLAYER;

        return SessionManager::RestartResponse::ACCEPTED_RESTART_SESSION;
    }

    SessionManager::GameState SessionManager::gameState() const {
        return _state;
    }

    std::string SessionManager::gameStateDescription() const {
        switch (_state) {
            case GameState::WAITING_FOR_PLAYER :
                return "waiting for players joining...";
            case GameState::PLACING_SHIPS :
                return "waiting for players to layout ships...";
            case GameState::PLAYER_1_TURN :
                return std::string("waiting for ") + players[0].username() + std::string(" to guess...");
            case GameState::PLAYER_2_TURN :
                return std::string("waiting for ") + players[1].username() + std::string(" to guess...");
            case GameState::TERMINATED :
                return "Game Over";
            default :
                return "<unknown>";
        };
    }

    bool SessionManager::hasPlayer(const std::string &username) const {
        const auto& it = std::find_if(players.begin(), players.end(), [&username](const PlayerData &p){ return p.username() == username;});
        return it!=players.end();
    }

    unsigned int SessionManager::nPlayers() const {
        return players.size();
    }

    int SessionManager::getPlayerId(const std::string &username) const {
        const auto& it = std::find_if(players.begin(), players.end(), [&username](const PlayerData &p){ return p.username() == username;});
        return it!=players.end() ? it->id() : -1;
    }

    std::string SessionManager::getPlayerName(int id) const {
        return id>=0 && id<2 && id<players.size() ? players[id].username() : std::string("<not-found>");
    }

}
