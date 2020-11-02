//
// Created by david on 01/11/2020.
//

#include "Ship.hpp"

namespace {

    constexpr char AircraftCarrierSymbol = 'A';
    constexpr char BattleshipSymbol = 'B';
    constexpr char CruiserSymbol = 'C';
    constexpr char DestroyerSymbol = 'D';
    constexpr char SubmarineSymbol = 'S';

    constexpr unsigned int AircraftCarrierSize = 5;
    constexpr unsigned int BattleshipSize = 4;
    constexpr unsigned int CruiserSize = 3;
    constexpr unsigned int DestroyerSize = 2;
    constexpr unsigned int SubmarineSize = 3;

}

namespace Battleships
{

    Ship::Ship(Ship::Type t, Coordinate topLeftCoordinate, Orientation orientation)
    : _topLeftCoordinate(topLeftCoordinate), _orientation(orientation)
    {
        switch (t) {
            case Type::AIRCRAFT_CARRIER:
                _size = AircraftCarrierSize;
                _symbol = AircraftCarrierSymbol;
                break;
            case Type::BATTLESHIP:
                _size = BattleshipSize;
                _symbol = BattleshipSymbol;
                break;
            case Type::CRUISER:
                _size = CruiserSize;
                _symbol = CruiserSymbol;
                break;
            case Type::DESTROYER:
                _size = DestroyerSize;
                _symbol = DestroyerSymbol;
                break;
            case Type::SUBMARINE:
                _size = SubmarineSize;
                _symbol = SubmarineSymbol;
                break;
            default:
                // switch case code smell
                throw std::runtime_error("couldn't resolve ship type when placing ship");
        }
    }

    char Ship::symbol() const {
        return _symbol;
    }

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




}