//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_SESSIONSUMMARYDTO_HPP
#define BATTLESHIPS_SESSIONSUMMARYDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class SessionSummaryDto : public oatpp::DTO {

    DTO_INIT(SessionSummaryDto, DTO)

    DTO_FIELD(Boolean, player1Joined, "player1_joined");
    DTO_FIELD(UInt32, idPlayer1, "player1_id");
    DTO_FIELD(String, namePlayer1, "player1_name");

    DTO_FIELD(Boolean, player2Joined, "player2_joined");
    DTO_FIELD(UInt32, idPlayer2, "player2_id");
    DTO_FIELD(String, namePlayer2, "player2_name");

    DTO_FIELD(UInt32, gameStatus, "game_status_code");
    DTO_FIELD(String, gameStatusDescription, "game_status_description");
};

#include OATPP_CODEGEN_END(DTO)

#endif //BATTLESHIPS_SESSIONSUMMARYDTO_HPP
