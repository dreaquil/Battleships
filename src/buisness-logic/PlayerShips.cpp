//
// Created by david on 02/11/2020.
//

#include "PlayerShips.hpp"
#include "buisness-logic/Coordinate.hpp"


Battleships::PlayerShips::PlayerShips(const PlayerShipPositionsDto& dto) :
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
