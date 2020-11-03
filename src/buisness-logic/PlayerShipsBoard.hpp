//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_PLAYERSHIPSBOARD_HPP
#define BATTLESHIPS_PLAYERSHIPSBOARD_HPP

#include <vector>
#include <memory>
#include "buisness-logic/Peg.hpp"
#include "buisness-logic/PlayerShipStore.hpp"

namespace Battleships {

    class PlayerShipsBoard {
    public:
    private:
        std::vector<Peg> pegs; // pegs in this board
    };

}


#endif //BATTLESHIPS_PLAYERSHIPSBOARD_HPP
