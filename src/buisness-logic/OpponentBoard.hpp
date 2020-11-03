//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_OPPONENTBOARD_HPP
#define BATTLESHIPS_OPPONENTBOARD_HPP

#include "buisness-logic/Peg.hpp"

#include <vector>
#include "buisness-logic/PlayerShipsBoard.hpp"

namespace Battleships {

    class OpponentBoard {
    public:
    private:
        const PlayerShipsBoard& playerBoardForOpponent;
    };

}


#endif //BATTLESHIPS_OPPONENTBOARD_HPP
