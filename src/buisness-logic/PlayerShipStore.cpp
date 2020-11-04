//
// Created by david on 02/11/2020.
//

#include <algorithm>
#include "PlayerShipStore.hpp"
#include "buisness-logic/Coordinate.hpp"


Battleships::PlayerShipStore::PlayerShipStore(const PlayerShipPositionsDto& dto) :
_ships(
        {
            {
               {Ship(
                       Ship::Type::AIRCRAFT_CARRIER,
                       dto.aircraftCarrier_topLeftRow,
                       dto.aircraftCarrier_topLeftColumn,
                       dto.aircraftCarrier_orientation)},
               {Ship(
                       Ship::Type::BATTLESHIP,
                       dto.battleship_topLeftRow,
                       dto.battleship_topLeftColumn,
                       dto.battleship_orientation)},
               {Ship(
                       Ship::Type::CRUISER,
                       dto.cruiser_topLeftRow,
                       dto.cruiser_topLeftColumn,
                       dto.cruiser_orientation)},
               {Ship(
                       Ship::Type::DESTROYER,
                       dto.destroyer_topLeftRow,
                       dto.destroyer_topLeftColumn,
                       dto.destroyer_orientation)},
               {Ship(
                       Ship::Type::SUBMARINE,
                       dto.submarine_topLeftRow,
                       dto.submarine_topLeftColumn,
                       dto.submarine_orientation)}
            }
        })
        {}

bool Battleships::PlayerShipStore::isValid() const {

    if (std::any_of(_ships.begin(),_ships.end(),[](const Ship& s){return !s.isValid();}))
        return false;

    // Too dirty... check of ship overlaps
    for(auto aIter = _ships.begin(); aIter<_ships.end(); ++aIter){
        for(auto bIter = aIter+1; bIter<_ships.end(); ++bIter){
            if (aIter->isOverLapping(*bIter)) return false;
        }
    }

    return true;
}

Battleships::PlayerShipStore::const_iterator Battleships::PlayerShipStore::begin() const {
    return _ships.begin();
}

Battleships::PlayerShipStore::const_iterator Battleships::PlayerShipStore::end() const {
    return _ships.end();
}

Battleships::Ship *Battleships::PlayerShipStore::getShipAt(const Battleships::Coordinate &pos) {

    for (auto& ship : _ships)
    {
        if(ship.isOccupying(pos)) return &ship;
    }
    return nullptr;
}

bool Battleships::PlayerShipStore::allSunk() const {
    return std::all_of(_ships.begin(),_ships.end(),[](const Ship& s){return s.isSunk();});
}
