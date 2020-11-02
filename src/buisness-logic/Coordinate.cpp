//
// Created by david on 01/11/2020.
//

#include "buisness-logic/Coordinate.hpp"

namespace Battleships {

    Coordinate::Coordinate(Row r, Column c) : row(r), column(c)
    {
    }

    Coordinate Coordinate::shiftDown(unsigned int nCol) {

        int iNewRow = static_cast<int>(row) + nCol;
        Row newRow = iNewRow>=static_cast<int>(Row::nRow) ? Row::Invalid : static_cast<Row>(iNewRow);

        return Coordinate(newRow, column);
    }

    Coordinate Coordinate::shiftRight(unsigned int nRow) {

        int iNewColumn = static_cast<int>(column) + nRow;
        Column newColumn = iNewColumn>=static_cast<int>(Column::nColumn) ? Column::Invalid : static_cast<Column>(iNewColumn);

        return Coordinate(row, newColumn);
    }

}
