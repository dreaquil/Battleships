//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_TURNGUESSDTO_HPP
#define BATTLESHIPS_TURNGUESSDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

ENUM(Result, v_int32,
     VALUE(HIT, 0, "Hit"),
     VALUE(HIT_AND_SUNK, 1, "Hit and sunk"),
     VALUE(MISS, 2, "Miss"),
     VALUE(INVALID, 3, "Illegal guess")
)

class TurnGuessDto : public oatpp::DTO {

    DTO_INIT(TurnGuessDto, DTO)

    DTO_FIELD(Int32, id);
    DTO_FIELD(Int32, iRow, "row");
    DTO_FIELD(Int32, iColumn, "column");

    DTO_FIELD(Enum<Result>::AsString, result, "result");
};

#include OATPP_CODEGEN_END(DTO)

#endif //BATTLESHIPS_TURNGUESSDTO_HPP
