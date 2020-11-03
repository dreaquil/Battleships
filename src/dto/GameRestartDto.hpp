//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_GAMERESTARTDTO_HPP
#define BATTLESHIPS_GAMERESTARTDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class GameRestartDto : public oatpp::DTO {

    DTO_INIT(GameRestartDto, DTO)

    DTO_FIELD(Int32, id);
};

#include OATPP_CODEGEN_END(DTO)


#endif //BATTLESHIPS_GAMERESTARTDTO_HPP
