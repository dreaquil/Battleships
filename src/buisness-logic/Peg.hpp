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
        enum class PlacementResult
        {
            INSERTED,
            NOT_INSERTED_INVALID_COORDINATE,
            NOT_INSERTED_PEG_ALREADY_PLACED,
        };

        enum class Colour {
            RED, // corresponds to a hit
            WHITE, // corresponds to a miss
        } colour;

        Coordinate coordinate;
    };
}

#endif //BATTLESHIPS_PEG_HPP
