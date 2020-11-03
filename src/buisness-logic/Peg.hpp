//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_PEG_HPP
#define BATTLESHIPS_PEG_HPP

#include "Coordinate.hpp"

namespace Battleships
{
    struct Peg
    {
        enum class Colour {
            RED, // corresponds to a hit
            WHITE, // corresponds to a miss
        } colour;

        Coordinate coordinate;
    };
}

#endif //BATTLESHIPS_PEG_HPP
