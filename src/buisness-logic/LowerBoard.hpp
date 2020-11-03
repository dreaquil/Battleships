//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_LOWERBOARD_HPP
#define BATTLESHIPS_LOWERBOARD_HPP

#include <vector>
#include <memory>
#include "buisness-logic/Peg.hpp"
#include "buisness-logic/PlayerShipStore.hpp"

namespace Battleships {

    class LowerBoard {
    public:
        Peg::PlacementResult placePeg(Peg p);
        std::vector<Peg> pegs() const;
        [[depricated]] bool isSetup() const;
        void positionShips(const PlayerShipPositionsDto& dto);
    private:
        std::vector<Peg> _pegs; // pegs in this board
        std::unique_ptr<PlayerShipStore> shipsStore;
    };

}


#endif //BATTLESHIPS_LOWERBOARD_HPP
