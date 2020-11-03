//
// Created by david on 02/11/2020.
//

#include <vector>
#include <algorithm>
#include "SessionManager.hpp"
#include "buisness-logic/PlayerData.hpp"

#include "dto/AddPlayerDto.hpp"
#include "dto/PlayerShipPositionsDto.hpp"

namespace Battleships {


    SessionManager::AddPlayerResponse SessionManager::addPlayer(const AddPlayerDto &dto) {

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

        int iPlayer = dto.id;

        switch (_state){
            case GameState::PLACING_SHIPS : {

                if (iPlayer>=nPlayers()) return ShipPlacementResponse::UNSPECIFIED_ERROR;

                PlayerShipStore shipsLayout(dto);
                if (!shipsLayout.isValid()) return ShipPlacementResponse::REJECTED_INVALID_LAYOUT;

                players[iPlayer].positionShips(dto);
                unsigned int iOpponent = iPlayer==0 ? 1 : 0;

                if (!players[iOpponent].isSetup()) return ShipPlacementResponse::ACCEPTED_UPDATED_SHIP_POSITIONS_WAITING_FOR_OTHER_PLAYER;

                _state = GameState::PLAYER_1_TURN;

                return ShipPlacementResponse::ACCEPTED_UPDATED_SHIP_POSITIONS_GAME_STARTING;
            }
            default : {
                return ShipPlacementResponse::REJECTED_CANNOT_PLACE_SHIPS_NOW;
            };
        }
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
        return std::__cxx11::string();
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

    SessionManager::GuessResponse SessionManager::playerGuess(const PlayerGuessDto &dto) {
        return SessionManager::GuessResponse::REJECTED_UNRECOGNISED_PLAYER; // todo
    }

}
