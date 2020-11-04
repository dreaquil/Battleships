//
// Created by david on 01/11/2020.
//

#include "buisness-logic/Coordinate.hpp"

namespace Battleships {

    Coordinate::Coordinate(Row r, Column c) : _row(r), _column(c)
    {}

    bool Coordinate::operator==(const Coordinate &other) const {
        return
                this->isValid() &&
                other.isValid() &&
                this->_row == other._row &&
                this->_column == other._column;
    }

    bool Coordinate::operator<(const Coordinate &other) const {
        return this->row()==other.row() ? this->column()<other.column() : this->row()<other.row();
    }

    Coordinate Coordinate::shiftDown(unsigned int nCol) {

        int iNewRow = static_cast<int>(_row) + nCol;
        Row newRow = iNewRow>=static_cast<int>(Row::nRow) ? Row::Invalid : static_cast<Row>(iNewRow);

        return Coordinate(newRow, _column);
    }

    Coordinate Coordinate::shiftRight(unsigned int nRow) {

        int iNewColumn = static_cast<int>(_column) + nRow;
        Column newColumn = iNewColumn>=static_cast<int>(Column::nColumn) ? Column::Invalid : static_cast<Column>(iNewColumn);

        return Coordinate(_row, newColumn);
    }

    bool Coordinate::isValid() const {

        return (_row == Row::A ||
                _row == Row::B ||
                _row == Row::C ||
                _row == Row::D ||
                _row == Row::E ||
                _row == Row::F ||
                _row == Row::G ||
                _row == Row::H ||
                _row == Row::I ||
                _row == Row::J)
                &&
                (int(_column) >= 0 && int(_column) <= 9);
    }

    Row Coordinate::row() const {
        return _row;
    }

    Column Coordinate::column() const {
        return _column;
    }

}
