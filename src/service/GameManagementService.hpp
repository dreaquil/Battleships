
#ifndef GAMESERVICE_HPP
#define GAMESERVICE_HPP

#include "db/GameStateDbClient.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class GameManagementService {
public:

  oatpp::Object<GameDto> createGame(const oatpp::Object<GameDto>& dto);
  oatpp::Object<GameDto> getGameById(const oatpp::Int32& id, const std::shared_ptr<oatpp::orm::Connection>& connection = nullptr);

  oatpp::Object<PlayerDto> addPlayer(const oatpp::Object<PlayerDto>& dto);
  oatpp::Object<PlayerDto> getPlayerById(const oatpp::Int32& id, const std::shared_ptr<oatpp::orm::Connection>& connection = nullptr);
  oatpp::Object<PageDto<oatpp::Object<PlayerDto>>> getPlayers();



private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<GameStateDbClient>, m_database); // Inject database component
};

#endif //GAMESERVICE_HPP
