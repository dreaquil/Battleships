//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_GAMEPLAYCONTROLLER_HPP
#define BATTLESHIPS_GAMEPLAYCONTROLLER_HPP

#include "LowerBoard.hpp"
#include "Coordinate.hpp"
#include "Peg.hpp"

/*
 * Todo:
 * Peg placement on player's lower board is mirrored on the opponent's upper board,
 * Consider this to reduce the logic
 */

namespace Battleships {

    class GameplayController {
    public:

        enum class GuessResponse {
            ACCEPTED_HIT,
            ACCEPTED_HIT_AND_SUNK,
            ACCEPTED_HIT_AND_SUNK_WIN_CONDITION,
            ACCEPTED_MISS,
            REJECTED_INVALID_COORDINATE,
            REJECTED_UNRECOGNISED_PLAYER,
            REJECTED_USER_CANNOT_GUESS_NOW,
        };

        bool isPlayer1Setup() const;
        void positionPlayer1Ships(const PlayerShipPositionsDto& dto);
        std::vector<Peg> player1UpperBoardPegs() const;
        std::vector<Peg> player1LowerBoardPegs() const;
        GameplayController::GuessResponse handlePlayer1Guess(const Coordinate& pos);

        bool isPlayer2Setup() const;
        void positionPlayer2Ships(const PlayerShipPositionsDto& dto);
        std::vector<Peg> player2UpperBoardPegs() const;
        std::vector<Peg> player2LowerBoardPegs() const;
        GameplayController::GuessResponse handlePlayer2Guess(const Coordinate& pos);

    private:
        LowerBoard m_p1LowerBoard;
        LowerBoard m_p2LowerBoard;
    };

}

#endif //BATTLESHIPS_GAMEPLAYCONTROLLER_HPP
