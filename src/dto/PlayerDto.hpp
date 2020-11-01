//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_PLAYERDTO_HPP
#define BATTLESHIPS_PLAYERDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class PlayerDto : public oatpp::DTO {

    DTO_INIT(PlayerDto, DTO)

    DTO_FIELD(Int32, id);
    DTO_FIELD(String, userName, "name");

};

#include OATPP_CODEGEN_END(DTO)


#endif //BATTLESHIPS_PLAYERDTO_HPP
