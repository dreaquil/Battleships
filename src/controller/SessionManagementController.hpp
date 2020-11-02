//
// Created by david on 31/10/2020.
//

#ifndef BATTLESHIPS_SESSIONMANAGEMENTCONTROLLER_HPP
#define BATTLESHIPS_SESSIONMANAGEMENTCONTROLLER_HPP

#include "service/GameManagementService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


/**
 * SessionManager Management REST controller.
 */
class SessionManagementController : public oatpp::web::server::api::ApiController {
public:
    SessionManagementController(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
    GameManagementService m_gameManagementService; // Create game service.
public:

    static std::shared_ptr<SessionManagementController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ){
        return std::make_shared<SessionManagementController>(objectMapper);
    }

    ENDPOINT_INFO(createGame) {
            info->summary = "Create new SessionManager";

            info->addConsumes<Object<GameDto>>("application/json");

            info->addResponse<Object<GameDto>>(Status::CODE_200, "application/json");
            info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
            info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "game", createGame,
    BODY_DTO(Object<GameDto>, gameDto))
    {
        return createDtoResponse(Status::CODE_200, m_gameManagementService.createGame(gameDto));
    }

    ENDPOINT_INFO(createPlayer) {
        info->summary = "Create new PlayerData";

        info->addConsumes<Object<PlayerDto>>("application/json");

        info->addResponse<Object<PlayerDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "player", createPlayer,
             BODY_DTO(Object<PlayerDto>, playerDto))
    {
        return createDtoResponse(Status::CODE_200, m_gameManagementService.addPlayer(playerDto));
    }

    ENDPOINT_INFO(getPlayers) {
        info->summary = "get all stored players";

        info->addResponse<oatpp::Object<PlayersPageDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "players", getPlayers)
    {
        return createDtoResponse(Status::CODE_200, m_gameManagementService.getPlayers());
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen


#endif //BATTLESHIPS_SESSIONMANAGEMENTCONTROLLER_HPP