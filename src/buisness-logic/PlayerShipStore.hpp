//
// Created by david on 02/11/2020.
//

#ifndef BATTLESHIPS_PLAYERSHIPS_HPP
#define BATTLESHIPS_PLAYERSHIPS_HPP

#include "buisness-logic/Ship.hpp"
#include "dto/PlayerShipPositionsDto.hpp"
#include <array>

namespace Battleships {

    class Ship;

    class PlayerShips {
    public:
        PlayerShips(const PlayerShipPositionsDto& ships);

        bool areValid() const;
    private:
        std::array<Ship,5> _ships;
    };

}


#endif //BATTLESHIPS_PLAYERSHIPS_HPP
