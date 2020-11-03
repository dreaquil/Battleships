//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_ADDPLAYERDTO_HPP
#define BATTLESHIPS_ADDPLAYERDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddPlayerDto : public oatpp::DTO {

    DTO_INIT(AddPlayerDto, DTO)

    DTO_FIELD(UInt32, id);
    DTO_FIELD(String, userName, "name");
};

#include OATPP_CODEGEN_END(DTO)


#endif //BATTLESHIPS_ADDPLAYERDTO_HPP
