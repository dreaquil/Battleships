//
// Created by david on 01/11/2020.
//

#include "buisness-logic/Coordinate.hpp"

namespace Battleships {

    Coordinate::Coordinate(Row r, Column c) : row(r), column(c)
    {}

    bool Coordinate::operator==(const Coordinate &other) {
        return
        this->isValid() &&
        other.isValid() &&
        this->row == other.row &&
        this->column == other.column;
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

    bool Coordinate::isValid() const {

        return (row == Row::A ||
                row == Row::B ||
                row == Row::C ||
                row == Row::D ||
                row == Row::E ||
                row == Row::F ||
                row == Row::G ||
                row == Row::H ||
                row == Row::I ||
                row == Row::J)
                &&
                (int(column) >= 0 && int(column) <= 9);
    }

}
