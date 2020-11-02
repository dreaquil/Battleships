//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_SHIPPOSITIONDTO_HPP
#define BATTLESHIPS_SHIPPOSITIONDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class ShipPositionDto : public oatpp::DTO {

    DTO_INIT(ShipPositionDto, DTO)

    DTO_FIELD(Int8, topLeftRow);
    DTO_FIELD(Int8, topLeftColumn);
    DTO_FIELD(Int8, orientation); // 'H' - horizontal, 'V' - Vertical
    DTO_FIELD(Int8, type); // valid ship types are 'A', 'B', 'C', 'D', 'S'

};

#include OATPP_CODEGEN_END(DTO)

#endif //BATTLESHIPS_SHIPPOSITIONDTO_HPP
