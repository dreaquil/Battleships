//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_COORDINATE_HPP
#define BATTLESHIPS_COORDINATE_HPP

#include "buisness-logic/Column.hpp"
#include "buisness-logic/Row.hpp"

namespace Battleships {

    class Coordinate {
    public:
        Coordinate(Row r, Column c) : row(r), column(c) {}

    private:
        Row row;
        Column column;

        Coordinate() = delete;
    };

}

#endif //BATTLESHIPS_COORDINATE_HPP
