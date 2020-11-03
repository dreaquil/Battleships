//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_GAMEPLAYCONTROLLER_HPP
#define BATTLESHIPS_GAMEPLAYCONTROLLER_HPP

#include "LowerBoard.hpp"
#include "UpperBoard.hpp"
#include "Coordinate.hpp"

/*
 * Todo:
 * Peg placement on player's lower board is mirrored on the opponent's upper board,
 * Consider this to reduce the logic
 */

namespace Battleships {

    enum class GuessResponse {
        ACCEPTED_HIT,
        ACCEPTED_HIT_AND_SUNK,
        ACCEPTED_HIT_AND_SUNK_WIN_CONDITION,
        ACCEPTED_MISS,
        REJECTED_INVALID_COORDINATE,
        REJECTED_UNRECOGNISED_PLAYER,
        REJECTED_USER_CANNOT_GUESS_NOW,
    };

    class GameplayController {
    public:

        GuessResponse placePin(const Coordinate& pos);

        bool isPlayer1Setup() const;
        bool isPlayer2Setup() const;
        void positionPlayer1Ships(const PlayerShipPositionsDto& dto);
        void positionPlayer2Ships(const PlayerShipPositionsDto& dto);

    private:
        LowerBoard m_p1LowerBoard;
        UpperBoard m_p1UpperBoard;
        LowerBoard m_p2LowerBoard;
        UpperBoard m_p2UpperBoard;
    };

}

#endif //BATTLESHIPS_GAMEPLAYCONTROLLER_HPP
