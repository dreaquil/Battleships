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

        using const_iterator = const std::array<Ship,5>::const_iterator;
        const_iterator begin() const;
        const_iterator end() const;

        // Smells...
        Ship* getShipAt(const Coordinate& pos);

        bool isValid() const;
        bool allSunk() const;
    private:
        std::array<Ship,5> _ships;
    };

}


#endif //BATTLESHIPS_PLAYERSHIPSTORE_HPP
