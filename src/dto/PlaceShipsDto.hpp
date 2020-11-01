//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_PLACESHIPSDTO_HPP
#define BATTLESHIPS_PLACESHIPSDTO_HPP

#include "buisness-logic/Coordinate.hpp"
#include "buisness-logic/Orientation.hpp"

namespace Battleships {

    struct PlaceShipsDto {
        Coordinate AircraftCarrierTopLeft = Coordinate(Row::A, Column::One);
        Orientation AircraftCarrierOrientation = Orientation::Horizontal;

        Coordinate BattleshipTopLeft = Coordinate(Row::B, Column::One);
        Orientation BattleshipOrientation = Orientation::Horizontal;

        Coordinate CruiserTopLeft = Coordinate(Row::C, Column::One);
        Orientation CruiserOrientation = Orientation::Horizontal;

        Coordinate DestroyerTopLeft = Coordinate(Row::D, Column::One);
        Orientation DestroyerOrientation = Orientation::Horizontal;

        Coordinate SubmarineTopLeft = Coordinate(Row::D, Column::Four);
        Orientation SubmarineOrientation = Orientation::Horizontal;
    };

}

#endif //BATTLESHIPS_PLACESHIPSDTO_HPP
