//
// Created by david on 02/11/2020.
//

#ifndef BATTLESHIPS_PLAYERSHIPPOSITIONSDTO_HPP
#define BATTLESHIPS_PLAYERSHIPPOSITIONSDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class PlayerShipPositionsDto : public oatpp::DTO {

    DTO_INIT(PlayerShipPositionsDto, DTO)

    DTO_FIELD(Int8, aircraftCarrier_topLeftRow); // A...J
    DTO_FIELD(Int8, aircraftCarrier_topLeftColumn); // 0...9
    DTO_FIELD(Int8, aircraftCarrier_orientation); // 'H' - horizontal, 'V' - Vertical

    DTO_FIELD(Int8, battleship_topLeftRow); // A...J
    DTO_FIELD(Int8, battleship_topLeftColumn); // 0...9
    DTO_FIELD(Int8, battleship_orientation); // 'H' - horizontal, 'V' - Vertical

    DTO_FIELD(Int8, cruiser_topLeftRow); // A...J
    DTO_FIELD(Int8, cruiser_topLeftColumn); // 0...9
    DTO_FIELD(Int8, cruiser_orientation); // 'H' - horizontal, 'V' - Vertical

    DTO_FIELD(Int8, submarine_topLeftRow); // A...J
    DTO_FIELD(Int8, submarine_topLeftColumn); // 0...9
    DTO_FIELD(Int8, submarine_orientation); // 'H' - horizontal, 'V' - Vertical

    DTO_FIELD(Int8, destroyer_topLeftRow); // A...J
    DTO_FIELD(Int8, destroyer_topLeftColumn); // 0...9
    DTO_FIELD(Int8, destroyer_orientation); // 'H' - horizontal, 'V' - Vertical
};

#include OATPP_CODEGEN_END(DTO)

#endif //BATTLESHIPS_PLAYERSHIPPOSITIONSDTO_HPP
