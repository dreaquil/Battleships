//
// Created by david on 02/11/2020.
//

#ifndef BATTLESHIPS_SESSIONMANAGER_HPP
#define BATTLESHIPS_SESSIONMANAGER_HPP

#include <memory>

#include "buisness-logic/PlayerData.hpp"
#include "buisness-logic/PlayerShips.hpp"



namespace Battleships {

    class SessionManager {
    public:

        enum class AddPlayerResponse {
            ACCEPTED_JOINED_SESSION_AS_PLAYER_1,
            ACCEPTED_JOINED_SESSION_AS_PLAYER_2,
            REJECTED_SESSION_FULL,
            REJECTED_USER_ALREADY_REGISTERED,
            REJECTED_SESSION_IN_PROGRESS,
        };
        AddPlayerResponse addPlayer(const PlayerData& p);

        enum class ShipPlacementResponse {
            ACCEPTED_UPDATED_SHIP_POSITIONS,
            REJECTED_INVALID_LAYOUT,
            REJECTED_UNRECOGNISED_PLAYER,
            REJECTED_CANNOT_PLACE_SHIPS_NOW,
        };
        ShipPlacementResponse placeShips(const PlayerData& p, PlayerShips& ships);

        enum class GuessResponse {
            ACCEPTED_HIT,
            ACCEPTED_HIT_AND_SUNK,
            ACCEPTED_HIT_AND_SUNK_WIN_CONDITION,
            REJECTED_INVALID_COORDINATE,
            REJECTED_UNRECOGNISED_PLAYER,
            REJECTED_USER_CANNOT_GUESS_NOW,
        };
        GuessResponse guess(const PlayerData&, const std::string& username);

        enum class TerminateResponse {
            ACCEPTED_RESTART_SESSION,
            REJECTED_UNRECOGNISED_PLAYER,
        };
        TerminateResponse terminate(const PlayerData&, const std::string& username);

    private:

        std::unique_ptr<PlayerData> p1;
        std::unique_ptr<PlayerData> P2;

        enum class GameState {
            WAITING_FOR_PLAYER_ONE,
            PLACING_SHIPS,
            PLAYER_1_TURN,
            PLAYER_2_TURN,
            TERMINATED,
        } _state = GameState::WAITING_FOR_PLAYER_ONE;
    };

}

#endif //BATTLESHIPS_SESSIONMANAGER_HPP