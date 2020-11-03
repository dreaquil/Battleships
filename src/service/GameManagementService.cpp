
#include "GameManagementService.hpp"

#define UNWRAP(X) (*X.get())
#define TO_STR(X) (X->std_str())

oatpp::Object<SessionSummaryDto> GameManagementService::sessionSummary() {

    int nPlayer = m_sessionManager.nPlayers();
    bool player1Joined = nPlayer > 0;
    bool player2Joined = nPlayer > 1;

    oatpp::Object<SessionSummaryDto> ExternalResponse;

    ExternalResponse->player1Joined = player1Joined;
    ExternalResponse->idPlayer1 = player1Joined ? 0 : -1;
    ExternalResponse->namePlayer1 = m_sessionManager.getPlayerName(0).c_str();

    ExternalResponse->player2Joined = player2Joined;
    ExternalResponse->idPlayer2 = player2Joined ? 1 : -1;
    ExternalResponse->namePlayer2 = m_sessionManager.getPlayerName(1).c_str();

    ExternalResponse->gameStatus = int(m_sessionManager.gameState());
    ExternalResponse->gameStatusDescription = m_sessionManager.gameStateDescription().c_str();

    return ExternalResponse;
}

oatpp::Object<AddPlayerDto> GameManagementService::addPlayer(const oatpp::Object<AddPlayerDto>& dto) {

    using InternalResponse = Battleships::SessionManager::AddPlayerResponse;

    auto ir = m_sessionManager.addPlayer(UNWRAP(dto));

    OATPP_ASSERT_HTTP(ir==InternalResponse::REJECTED_USER_ALREADY_REGISTERED, Status::CODE_417, "Session is already in progress");
    OATPP_ASSERT_HTTP(ir==InternalResponse::REJECTED_SESSION_IN_PROGRESS, Status::CODE_417, "Session is already in progress");
    OATPP_ASSERT_HTTP(ir==InternalResponse::UNSPECIFIED_ERROR, Status::CODE_500, "Unspecified Error");

    std::string playerName = TO_STR(dto->userName);
    bool hasPlayer = m_sessionManager.hasPlayer(playerName);
    int playerId = m_sessionManager.getPlayerId(playerName);
    playerName = hasPlayer ? playerName : "<not-found>";

    oatpp::Object<AddPlayerDto> ExternalResponse;
    ExternalResponse->id = playerId;
    ExternalResponse->userName = playerName.c_str();

    return ExternalResponse;
}




oatpp::Object<AddPlayerDto> GameManagementService::getPlayerById(const oatpp::Int32& id, const std::shared_ptr<oatpp::orm::Connection>& connection) {

    auto dbResult = m_database->getPlayerById(id, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "PlayerData not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<AddPlayerDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}







oatpp::Object<GameDto> GameManagementService::createGame(const oatpp::Object<GameDto>& dto) {

  auto dbResult = m_database->createGame(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto gameId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

  OATPP_LOGD("AAA", "new gameId=%d", gameId);

  return getGameById((v_int32) gameId);

}

oatpp::Object<GameDto> GameManagementService::getGameById(const oatpp::Int32& id, const std::shared_ptr<oatpp::orm::Connection>& connection) {

    auto dbResult = m_database->getGameById(id, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "SessionManager not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<GameDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}

