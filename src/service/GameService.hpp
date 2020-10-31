
#ifndef GAMESERVICE_HPP
#define GAMESERVICE_HPP

#include "db/GameDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class GameService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<GameDb>, m_database); // Inject database component
public:

  oatpp::Object<GameDto> createGame(const oatpp::Object<GameDto>& dto);
  oatpp::Object<GameDto> getGameById(const oatpp::Int32& id, const std::shared_ptr<oatpp::orm::Connection>& connection = nullptr);

};

#endif //GAMESERVICE_HPP
