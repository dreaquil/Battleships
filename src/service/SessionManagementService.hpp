
#ifndef GAMESERVICE_HPP
#define GAMESERVICE_HPP

#include "db/GameStateDbClient.hpp"
#include "dto/PageDto.hpp"
#include "dto/SessionSummaryDto.hpp"
#include "dto/StatusDto.hpp"
#include "dto/PlayerGuessDto.hpp"
#include "dto/GameRestartDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"
#include "buisness-logic/SessionManager.hpp"

class SessionManagementService {
public:

    oatpp::Object<SessionSummaryDto> sessionSummary();

    oatpp::Object<AddPlayerDto> addPlayer(const oatpp::Object<AddPlayerDto>& dto);
    oatpp::Object<StatusDto> placeShips(const oatpp::Object<PlayerShipPositionsDto>& dto);
    oatpp::Object<PlayerGuessDto> playerGuess(const oatpp::Object<PlayerGuessDto>& dto);
    oatpp::Object<StatusDto> restartGame(const oatpp::Object<GameRestartDto>& dto);


  oatpp::Object<GameDto> createGame(const oatpp::Object<GameDto>& dto);
  oatpp::Object<GameDto> getGameById(const oatpp::Int32& id, const std::shared_ptr<oatpp::orm::Connection>& connection = nullptr);

  oatpp::Object<AddPlayerDto> getPlayerById(const oatpp::Int32& id, const std::shared_ptr<oatpp::orm::Connection>& connection = nullptr);



private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<GameStateDbClient>, m_database); // Inject database component
    Battleships::SessionManager m_sessionManager;

};

#endif //GAMESERVICE_HPP
