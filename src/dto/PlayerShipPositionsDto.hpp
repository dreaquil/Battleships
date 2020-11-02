//
// Created by david on 02/11/2020.
//

#ifndef BATTLESHIPS_PLAYERSHIPPOSITIONSDTO_HPP
#define BATTLESHIPS_PLAYERSHIPPOSITIONSDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"


#include "dto/ShipPositionDto.hpp"
#include <array>

class PlayerShipsDto : public oatpp::DTO {


    std::array<ShipPositionDto,5> ships;

};

#endif //BATTLESHIPS_PLAYERSHIPPOSITIONSDTO_HPP
