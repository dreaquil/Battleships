//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_UPPERBOARD_HPP
#define BATTLESHIPS_UPPERBOARD_HPP

#include "buisness-logic/Peg.hpp"

#include <vector>
#include "buisness-logic/LowerBoard.hpp"

namespace Battleships {

    class UpperBoard {
    public:
        std::vector<Peg> pegs() const;
    private:
        const LowerBoard* playerBoardForOpponent;
    };

}


#endif //BATTLESHIPS_UPPERBOARD_HPP
