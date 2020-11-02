//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_SHIP_HPP
#define BATTLESHIPS_SHIP_HPP

#include <string>
#include <memory>

#include "buisness-logic/Coordinate.hpp"
#include "dto/ShipPositionDto.hpp"

namespace Battleships {

    class Ship {
    public:

        enum class Type : char
        {
            AIRCRAFT_CARRIER = 'A',
            BATTLESHIP = 'B',
            CRUISER = 'C',
            SUBMARINE = 'D',
            DESTROYER = 'E',

            nType = 5,
            Invalid,
        };

        enum class Orientation : char {
            Horizontal = 'H',
            Vertical = 'V',

            Invalid = '-',
        };

        Ship(Type t, Coordinate topLeftCoordinate, Orientation orientation);
        Ship(const ShipPositionDto& dto);

        unsigned int size() const;
        Coordinate topLeftCoordinate() const;
        Coordinate bottomRightCoordinate() const;

        bool isValid() const;
        bool isHangingOffEdge() const;
        bool hasValidType() const;
        bool hasValidSize() const;
        bool hasValidOrientation() const;

    private:

        bool hasHorizontalOrientation() const;
        Type _type;
        Orientation _orientation;
        Coordinate _topLeftCoordinate;
        unsigned int _size;

    };

    //bool shipsOverlapOneAnother(PlayerShipsDto layout); // intersects another ship
}

#endif //BATTLESHIPS_SHIP_HPP
