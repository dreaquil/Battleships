//
// Created by david on 01/11/2020.
//

#include <unordered_map>
#include "Ship.hpp"
#include "dto/ShipPositionDto.hpp"

namespace {

    using Type = Battleships::Ship::Type;
    using Orientation = Battleships::Ship::Orientation;
    using Row = Battleships::Row;
    using Column = Battleships::Column;

    const std::unordered_map<Battleships::Ship::Type,unsigned int> shipSizeMap =
            {
                    {Type::AIRCRAFT_CARRIER, 5},
                    {Type::BATTLESHIP, 4},
                    {Type::CRUISER, 3},
                    {Type::SUBMARINE, 3},
                    {Type::DESTROYER, 2},

                    {Type::nType, 0},
                    {Type::Invalid, 0},
            };

    Orientation orientationFrom(char o) {
        return o == 'H' ? Orientation::Horizontal : o == 'V' ? Orientation::Vertical : Orientation::Invalid;
    }

    Column columnFrom(char col){
        switch (col) {
            case '0'...'9' :
                return Column(col);
            default :
                return Column ::Invalid;
        }
    }

    Row rowFrom(char row){
        switch (row) {
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
                return Row(row);
            default :
                return Row::Invalid;
        }
    }

    Type typeFrom(char type) {
        switch (type) {
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'S':
                return Type(type);
            default :
                return Type::Invalid;
        }
    }


}

namespace Battleships
{

    Ship::Ship(Ship::Type t, Coordinate topLeftCoordinate, Orientation orientation)
    :  _type(t), _topLeftCoordinate(topLeftCoordinate), _orientation(orientation), _size(shipSizeMap.at(t))
    {}

    Ship::Ship(Type t, char topLeftRow, char topLeftColumn, char orientation) :
            _topLeftCoordinate(Coordinate(rowFrom(topLeftRow),columnFrom(topLeftColumn))),
            _orientation(orientationFrom(orientation)),
            _type(t)
    {}

    Ship::Ship(const ShipPositionDto &dto) :
            _orientation(orientationFrom(dto.orientation)),
            _type(typeFrom(dto.type)),
            _topLeftCoordinate(
                    Coordinate(
                            rowFrom(dto.topLeftRow),
                            columnFrom(dto.topLeftColumn)))
    {}

    unsigned int Ship::size() const {
        return _size;
    }

    bool Ship::hasHorizontalOrientation() const {
        return _orientation == Orientation::Horizontal;
    }

    Coordinate Ship::topLeftCoordinate() const {
        return _topLeftCoordinate;
    }

    Coordinate Ship::bottomRightCoordinate() const {
        return hasHorizontalOrientation() ? topLeftCoordinate().shiftRight(_size) : topLeftCoordinate().shiftDown(_size);
    }

    bool Ship::isHangingOffEdge() const {
        return topLeftCoordinate().isValid() && bottomRightCoordinate().isValid();
    }

    bool Ship::isValid() const {
        return isHangingOffEdge() && hasValidOrientation() && hasValidType();
    }

    bool Ship::hasValidType() const {
        return
        _type == Type::AIRCRAFT_CARRIER ||
        _type == Type::BATTLESHIP ||
        _type == Type::CRUISER ||
        _type == Type::DESTROYER ||
        _type == Type::SUBMARINE;
    }

    bool Ship::hasValidOrientation() const {
        return
        _orientation == Orientation::Horizontal ||
        _orientation == Orientation::Vertical;
    }

}