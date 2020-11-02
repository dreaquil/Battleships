//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_SHIPPOSITIONDTO_HPP
#define BATTLESHIPS_SHIPPOSITIONDTO_HPP

#include <array>

struct ShipPositionDto {

    // e.g. For Coordinate B4 - { 'B', '4' }
    char topLeftCoordinate[2] = {'-', '-'};

    // 'H' - horizontal, 'V' - Vertical
    char orientation = '-';

    // Only 'A', 'B', 'C', 'D','S' are valid
    char type = '-';

    char topLeftCoordinateRow() const {return topLeftCoordinate[0];}
    char topLeftCoordinateColumn() const {return topLeftCoordinate[1];}

};

#endif //BATTLESHIPS_SHIPPOSITIONDTO_HPP
