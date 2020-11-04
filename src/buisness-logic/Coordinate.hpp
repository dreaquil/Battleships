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
        Coordinate(Row r, Column c);
        bool operator==(const Coordinate& other) const;
        bool operator<(const Coordinate& other) const;

        Coordinate shiftDown(unsigned int nCol);
        Coordinate shiftRight(unsigned int nRow);

        bool isValid() const;
        Row row() const;
        Column column() const;

        Coordinate() = delete;

    private:
        Row _row;
        Column _column;
    };

}

#endif //BATTLESHIPS_COORDINATE_HPP
