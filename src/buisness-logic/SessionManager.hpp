//
// Created by david on 02/11/2020.
//

#ifndef BATTLESHIPS_SESSIONMANAGER_HPP
#define BATTLESHIPS_SESSIONMANAGER_HPP

#include <memory>

#include "dto/AddPlayerDto.hpp"
#include "dto/PlayerShipPositionsDto.hpp"

#include "buisness-logic/PlayerData.hpp"
#include "buisness-logic/PlayerShipStore.hpp"



namespace Battleships {

    class SessionManager {
    public:

        enum class AddPlayerResponse {
            ACCEPTED_JOINED_SESSION_AS_PLAYER_1,
            ACCEPTED_JOINED_SESSION_AS_PLAYER_2,
            REJECTED_SESSION_FULL,
            REJECTED_USER_ALREADY_REGISTERED,
            REJECTED_SESSION_IN_PROGRESS,
            UNSPECIFIED_ERROR,
        };
        AddPlayerResponse addPlayer(const AddPlayerDto &dto);

        enum class ShipPlacementResponse {
            ACCEPTED_UPDATED_SHIP_POSITIONS_WAITING_FOR_OTHER_PLAYER,
            ACCEPTED_UPDATED_SHIP_POSITIONS_GAME_STARTING,
            REJECTED_INVALID_LAYOUT,
            REJECTED_UNRECOGNISED_PLAYER,
            REJECTED_CANNOT_PLACE_SHIPS_NOW,
            UNSPECIFIED_ERROR,
        };
        ShipPlacementResponse placeShips(const PlayerShipPositionsDto &dto);

        enum class GuessResponse {
            ACCEPTED_HIT,
            ACCEPTED_HIT_AND_SUNK,
            ACCEPTED_HIT_AND_SUNK_WIN_CONDITION,
            REJECTED_INVALID_COORDINATE,
            REJECTED_UNRECOGNISED_PLAYER,
            REJECTED_USER_CANNOT_GUESS_NOW,
        };
        GuessResponse guess(unsigned int iPlayer, const std::string& username);

        enum class TerminateGameResponse {
            ACCEPTED_ABORTING_GAME,
        };
        TerminateGameResponse terminateGame();

        enum class RestartResponse {
            ACCEPTED_RESTART_SESSION,
        };
        RestartResponse restartGame();

        enum class GameState : int {
            WAITING_FOR_PLAYER = 1,
            PLACING_SHIPS = 2,
            PLAYER_1_TURN = 3,
            PLAYER_2_TURN = 4,
            TERMINATED = 5,
        };
        SessionManager::GameState gameState() const;
        std::string gameStateDescription() const;

        bool hasPlayer(const std::string &username) const;
        int getPlayerId(const std::string &username) const;
        std::string getPlayerName(int id) const;
        unsigned int nPlayers() const;


    private:
        GameState _state = GameState::WAITING_FOR_PLAYER;
        std::vector<PlayerData> players;
    };

}

#endif //BATTLESHIPS_SESSIONMANAGER_HPP
