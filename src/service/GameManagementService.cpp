
#include "GameManagementService.hpp"

#define UNWRAP(X) (*X.get())
#define TO_STR(X) (X->std_str())

oatpp::Object<SessionSummaryDto> GameManagementService::sessionSummary() {

    int nPlayer = m_sessionManager.nPlayers();
    bool player1Joined = nPlayer > 0;
    bool player2Joined = nPlayer > 1;

    auto ExternalResponse = oatpp::Object<SessionSummaryDto>::createShared();

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

    OATPP_ASSERT_HTTP(ir!=InternalResponse::REJECTED_USER_ALREADY_REGISTERED, Status::CODE_417, "Session is already in progress");
    OATPP_ASSERT_HTTP(ir!=InternalResponse::REJECTED_SESSION_IN_PROGRESS, Status::CODE_417, "Session is already in progress");
    OATPP_ASSERT_HTTP(ir!=InternalResponse::UNSPECIFIED_ERROR, Status::CODE_500, "Unspecified Error");

    std::string playerName = TO_STR(dto->userName);
    bool hasPlayer = m_sessionManager.hasPlayer(playerName);
    int playerId = m_sessionManager.getPlayerId(playerName);
    playerName = hasPlayer ? playerName : "<not-found>";

    auto ExternalResponse = oatpp::Object<AddPlayerDto>::createShared();
    //AddPlayerDto ExternalResponse;
    ExternalResponse->id = playerId;
    ExternalResponse->userName = playerName.c_str();

    return ExternalResponse;
}

oatpp::Object<StatusDto> GameManagementService::placeShips(const oatpp::Object<PlayerShipPositionsDto> &dto) {

    using InternalResponse = Battleships::SessionManager::ShipPlacementResponse;

    auto ir = m_sessionManager.placeShips(UNWRAP(dto));

    OATPP_ASSERT_HTTP(ir!=InternalResponse::REJECTED_INVALID_LAYOUT, Status::CODE_417, "Specified ship positions are illegal");
    OATPP_ASSERT_HTTP(ir!=InternalResponse::REJECTED_CANNOT_PLACE_SHIPS_NOW, Status::CODE_417, "Cannot accept ship positions at this time");
    OATPP_ASSERT_HTTP(ir!=InternalResponse::UNSPECIFIED_ERROR, Status::CODE_500, "Unspecified Error");

    auto ExternalResponse = oatpp::Object<StatusDto>::createShared();
    ExternalResponse->status = "OK";
    ExternalResponse->code = 200;
    ExternalResponse->message = "Ships have been placed successfully";

    return ExternalResponse;
}


oatpp::Object<PlayerGuessDto> GameManagementService::playerGuess(const oatpp::Object<PlayerGuessDto> &dto) {

    using InternalResponse = Battleships::SessionManager::GuessResponse;

    auto ir = m_sessionManager.playerGuess(UNWRAP(dto));

    auto ExternalResponse = oatpp::Object<PlayerGuessDto>::createShared();
    ExternalResponse->id = dto->id;
    ExternalResponse->iRow = dto->iRow;
    ExternalResponse->iColumn = dto->iColumn;

    switch (ir)
    {
        case InternalResponse::ACCEPTED_HIT : {
            ExternalResponse->result = PlayerGuessResult::HIT;
            break;
        }
        case InternalResponse::ACCEPTED_HIT_AND_SUNK :
        case InternalResponse::ACCEPTED_HIT_AND_SUNK_WIN_CONDITION :{
            ExternalResponse->result = PlayerGuessResult::HIT_AND_SUNK;
            break;
        }
        case InternalResponse::ACCEPTED_MISS :{
            ExternalResponse->result = PlayerGuessResult::MISS;
            break;
        }
        case InternalResponse::REJECTED_INVALID_COORDINATE :
        case InternalResponse::REJECTED_UNRECOGNISED_PLAYER :
        case InternalResponse::REJECTED_USER_CANNOT_GUESS_NOW :
        default : {
            ExternalResponse->result = PlayerGuessResult::INVALID;
        }
    }

    OATPP_ASSERT_HTTP(ir!=InternalResponse::REJECTED_INVALID_COORDINATE, Status::CODE_417, "Guess is invalid");
    OATPP_ASSERT_HTTP(ir!=InternalResponse::REJECTED_UNRECOGNISED_PLAYER, Status::CODE_417, "Unrecognised player ID");
    OATPP_ASSERT_HTTP(ir!=InternalResponse::REJECTED_USER_CANNOT_GUESS_NOW, Status::CODE_500, "Player not permitted to guess right now");

    return ExternalResponse;

}


oatpp::Object<StatusDto> GameManagementService::restartGame(const oatpp::Object<GameRestartDto> &dto) {

    using InternalResponse = Battleships::SessionManager::RestartResponse;

    auto ir = m_sessionManager.restartGame(UNWRAP(dto));
    auto ExternalResponse = oatpp::Object<StatusDto>::createShared();

    switch (ir) {
        case InternalResponse::ACCEPTED_RESTART_SESSION : {
            ExternalResponse->status = "OK";
            ExternalResponse->code = 417;
            ExternalResponse->message = "Permission denied";
        }
        case InternalResponse::REJECTED_UNRECOGNISED_PLAYER :
        default: {
            ExternalResponse->status = "OK";
            ExternalResponse->code = 200;
            ExternalResponse->message = "Session was restarted";
        }
    }
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
