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

    DTO_FIELD(UInt32, iPlayer, "your_player_no");
    DTO_FIELD(Boolean, waitingForOpponent, "found_opponent");
    DTO_FIELD(String, opponentUserName, "opponent");

};

#include OATPP_CODEGEN_END(DTO)

#endif //BATTLESHIPS_SESSIONSUMMARYDTO_HPP
