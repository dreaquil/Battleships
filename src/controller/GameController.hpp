//
// Created by david on 31/10/2020.
//

#ifndef BATTLESHIPS_GAMECONTROLLER_HPP
#define BATTLESHIPS_GAMECONTROLLER_HPP

#include "service/GameService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


/**
 * Game REST controller.
 */
class GameController : public oatpp::web::server::api::ApiController {
public:
    GameController(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
    GameService m_gameService; // Create game service.
public:

    static std::shared_ptr<GameController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ){
        return std::make_shared<GameController>(objectMapper);
    }

    ENDPOINT_INFO(createGame) {
            info->summary = "Create new Game";

            info->addConsumes<Object<GameDto>>("application/json");

            info->addResponse<Object<GameDto>>(Status::CODE_200, "application/json");
            info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
            info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "games", createGame,
    BODY_DTO(Object<GameDto>, gameDto))
    {
        return createDtoResponse(Status::CODE_200, m_gameService.createGame(gameDto));
    }


    ENDPOINT_INFO(getGameById) {
            info->summary = "Get one Game by gameId";

            info->addResponse<Object<GameDto>>(Status::CODE_200, "application/json");
            info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
            info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

            info->pathParams["gameId"].description = "Game Identifier";
    }
    ENDPOINT("GET", "games/{gameId}", getGameById,
    PATH(Int32, gameId))
    {
        return createDtoResponse(Status::CODE_200, m_gameService.getGameById(gameId));
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen


#endif //BATTLESHIPS_GAMECONTROLLER_HPP
