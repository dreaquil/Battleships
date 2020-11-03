//
// Created by david on 02/11/2020.
//

#ifndef BATTLESHIPS_PLAYERSHIPSTORE_HPP
#define BATTLESHIPS_PLAYERSHIPSTORE_HPP

#include "buisness-logic/Ship.hpp"
#include "dto/PlayerShipPositionsDto.hpp"
#include <array>

namespace Battleships {

    class Ship;

    class PlayerShipStore {
    public:
        PlayerShipStore(const PlayerShipPositionsDto& dto);

        bool isValid() const;
    private:
        std::array<Ship,5> _ships;
    };

}


#endif //BATTLESHIPS_PLAYERSHIPSTORE_HPP
