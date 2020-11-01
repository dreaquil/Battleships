//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_COORDINATE_HPP
#define BATTLESHIPS_COORDINATE_HPP

class Coordinate
{
public:
    Coordinate(unsigned int r, unsigned int c) : row(r), column(c) {}
private:
    unsigned int row;
    unsigned int column;
    Coordinate() = delete;
};

#endif //BATTLESHIPS_COORDINATE_HPP
