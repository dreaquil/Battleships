//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_SHIP_HPP
#define BATTLESHIPS_SHIP_HPP

#include <string>
#include <memory>

#include "buisness-logic/Coordinate.hpp"
#include "buisness-logic/Orientation.hpp"
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

        Ship(Type t, Coordinate topLeftCoordinate, Orientation orientation);
        Ship(Type t, char topLeftRow, char topLeftColumn, char orientation);
        Ship(const ShipPositionDto& dto);

        Orientation orientation() const;

        unsigned int size() const;
        Coordinate topLeftCoordinate() const;
        Coordinate bottomRightCoordinate() const;

        bool isValid() const;
        bool isHangingOffEdge() const;
        bool hasValidType() const;
        bool hasValidOrientation() const;
        bool isOverLapping(const Ship& other) const;
        bool isOccupying(Coordinate pos) const;
        bool isSunk() const;
        void hit();

    private:

        bool hasHorizontalOrientation() const;
        Type _type;
        Orientation _orientation;
        Coordinate _topLeftCoordinate;
        unsigned int _pegsUntilSunk;

    };

    //bool shipsOverlapOneAnother(PlayerShipsDto layout); // intersects another ship
}

#endif //BATTLESHIPS_SHIP_HPP
