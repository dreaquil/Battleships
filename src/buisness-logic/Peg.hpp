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
        enum class PlacementResult {
            INSERTED_HIT,
            INSERTED_HIT_AND_SUNK,
            INSERTED_HIT_AND_SUNK_WIN_CONDITION,
            INSERTED_MISS,
            NOT_INSERTED_INVALID_PLACEMENT,
        };

        enum class Colour {
            RED, // corresponds to a hit
            WHITE, // corresponds to a miss
        };

        Peg() = delete;
        Peg(Coordinate pos, Colour col) : coordinate(pos), colour(col) {}

        Colour colour;

        Coordinate coordinate;
    };
}

#endif //BATTLESHIPS_PEG_HPP
