//
// Created by david on 31/10/2020.
//

#ifndef BATTLESHIPS_GAMEDTO_HPP
#define BATTLESHIPS_GAMEDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

ENUM(Status, v_int32,
     VALUE(WAITING_FOR_PLAYER_ONE, 0, "WAITING_FOR_PLAYER_ONE"),
     VALUE(WAITING_FOR_PLAYER_TWO, 1, "WAITING_FOR_PLAYER_TWO"),
     VALUE(PLACING_SHIPS, 2, "PLACING_SHIPS"),
     VALUE(PLAYER_1_TURN, 3, "PLAYER_1_TURN"),
     VALUE(PLAYER_2_TURN, 4, "PLAYER_2_TURN"),
     VALUE(PLAYER_1_WINNER, 5, "PLAYER_1_WINNER"),
     VALUE(PLAYER_2_WINNER, 6, "PLAYER_2_WINNER"),
     VALUE(TERMINATED, 7, "TERMINATED")
)

class GameDto : public oatpp::DTO {

    DTO_INIT(GameDto, DTO)

    DTO_FIELD(Int32, id);
    DTO_FIELD(Enum<Status>::AsString, status, "status");

};

#include OATPP_CODEGEN_END(DTO)


#endif //BATTLESHIPS_GAMEDTO_HPP
