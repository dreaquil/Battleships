//
// Created by david on 31/10/2020.
//

#ifndef BATTLESHIPS_SESSIONMANAGEMENTAPI_HPP
#define BATTLESHIPS_SESSIONMANAGEMENTAPI_HPP

#include "SessionManagementService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


/**
 * SessionManager Management REST controller.
 */
class SessionManagementAPI : public oatpp::web::server::api::ApiController {
public:
    SessionManagementAPI(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:

    SessionManagementService m_gameManagementService; // Create game service.
public:

    static std::shared_ptr<SessionManagementAPI> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ){
        return std::make_shared<SessionManagementAPI>(objectMapper);
    }

    ENDPOINT_INFO(session_summary) {
        info->summary = "get game summary data";

        info->addResponse<oatpp::Object<SessionSummaryDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "session_summary", session_summary)
    {
        return createDtoResponse(Status::CODE_200, m_gameManagementService.sessionSummary());
    }

    ENDPOINT_INFO(join_session) {
        info->summary = "Join as new player";

        info->addConsumes<Object<AddPlayerDto>> ("application/json");

        info->addResponse<Object<AddPlayerDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_417, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "join_session", join_session, BODY_DTO(Object<AddPlayerDto>, playerDto))
    {
        return createDtoResponse(Status::CODE_200, m_gameManagementService.addPlayer(playerDto));
    }

    ENDPOINT_INFO(place_ships) {
        info->summary = "Specify ship positions for a single player";

        info->addConsumes<Object<PlayerShipPositionsDto>>("application/json");

        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_417, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "place_ships", place_ships, BODY_DTO(Object<PlayerShipPositionsDto>, dto))
    {
        return createDtoResponse(Status::CODE_200, m_gameManagementService.placeShips(dto));
    }

    ENDPOINT_INFO(player_guess) {
        info->summary = "Guess a coordinate";

        info->addConsumes<Object<PlayerGuessDto>>("application/json");

        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_417, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "player_guess", player_guess, BODY_DTO(Object<PlayerGuessDto>, dto))
    {
        return createDtoResponse(Status::CODE_200, m_gameManagementService.playerGuess(dto));
    }

    ENDPOINT_INFO(restart_game) {
        info->summary = "Terminates the current game";

        info->addConsumes<Object<GameRestartDto>>("application/json");

        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_417, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "restart_game", restart_game, BODY_DTO(Object<GameRestartDto>, dto))
    {
        return createDtoResponse(Status::CODE_200, m_gameManagementService.restartGame(dto));
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen


#endif //BATTLESHIPS_SESSIONMANAGEMENTAPI_HPP
