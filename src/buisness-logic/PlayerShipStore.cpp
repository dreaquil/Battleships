//
// Created by david on 02/11/2020.
//

#include <algorithm>
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

bool Battleships::PlayerShips::areValid() const {

    if (std::any_of(_ships.begin(),_ships.end(),[](const Ship& s){return !s.isValid();}))
        return false;

    return true;

    // Nasty - C masks?...
    /*
    {
        bool overlap[10][10] = {false};  // could return an error cell dto
        bool occupied[10][10] = {false};

        for (const auto &ship : _ships) {

            bool position[10][10] = {false};

            int iRow = int(ship.topLeftCoordinate().row());
            int iCol = int(ship.topLeftCoordinate().column());

            switch (ship.orientation()) {
                case Ship::Orientation::Horizontal :
                {
                    int colFinal = int(ship.bottomRightCoordinate().column());
                    for (;iCol<colFinal;++iCol)
                    {
                        position[iRow][iCol] = true;
                    }
                    break;
                }
                case Ship::Orientation::Vertical :
                {
                    int rowFinal = int(ship.bottomRightCoordinate().row());
                    for (;iRow<rowFinal;++iRow)
                    {
                        position[iRow][iCol] = true;
                    }
                    break;
                }
                default:
                    return false;
            }


        }
    }
     */
}
