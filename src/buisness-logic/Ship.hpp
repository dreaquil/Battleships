//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_SHIP_HPP
#define BATTLESHIPS_SHIP_HPP

#include <string>;
#include <memory>

#include "buisness-logic/Coordinate.hpp"

namespace Battleships {

    enum class Orientation {
        Horizontal,
        Vertical,
    };

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
        unsigned int size() const;
        Coordinate topLeftCoordinate() const;
        Coordinate bottomRightCoordinate() const;

        // bool isSunk() const;
        // bool isOverlapsAnother() const; // intersects another ship
        bool isHangingOffEdge() const;

    private:

        bool hasHorizontalOrientation() const;
        char _symbol;
        Orientation _orientation;
        Coordinate _topLeftCoordinate;
        unsigned int _size;

    };
}

#endif //BATTLESHIPS_SHIP_HPP
