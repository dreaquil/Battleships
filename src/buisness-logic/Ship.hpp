//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_SHIP_HPP
#define BATTLESHIPS_SHIP_HPP

#include <string>;
#include <memory>

#include "buisness-logic/Orientation.hpp"
#include "buisness-logic/Coordinate.hpp"

namespace Battleships {

    class Ship {
    public:

        enum class Type
        {
            AIRCRAFT_CARRIER,
            BATTLESHIP,
            CRUISER,
            SUBMARINE,
            DESTROYER,
        };

        Ship(Type t, Coordinate topLeftCoordinate, Orientation orientation);

        char symbol() const;
        char _symbol;

        unsigned int size() const;
        unsigned int _size;

        bool hasHorizontalOrientation() const;
        Orientation _orientation;

        Coordinate topLeftCoordinate() const;
        Coordinate bottomRightCoordinate() const;
        Coordinate _topLeftCoordinate;

        // bool isSunk() const;
        // bool isOverlapsAnother() const; // intersects another ship
        bool isHangingOffEdge() const;

    };
}

#endif //BATTLESHIPS_SHIP_HPP
