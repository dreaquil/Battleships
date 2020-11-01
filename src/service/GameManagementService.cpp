
#include "GameManagementService.hpp"

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
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Game not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<GameDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}

oatpp::Object<PlayerDto> GameManagementService::addPlayer(const oatpp::Object<PlayerDto>& dto) {

    auto dbResult = m_database->createPlayer(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto playerId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

    return getPlayerById((v_int32) playerId);

}


oatpp::Object<PlayerDto> GameManagementService::getPlayerById(const oatpp::Int32& id, const std::shared_ptr<oatpp::orm::Connection>& connection) {

    auto dbResult = m_database->getPlayerById(id, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Player not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PlayerDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}


oatpp::Object<PageDto<oatpp::Object<PlayerDto>>> GameManagementService::getPlayers() {

    auto dbResult = m_database->getAllPlayers();
    bool success = dbResult->isSuccess();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<PlayerDto>>>();

    auto page = PageDto<oatpp::Object<PlayerDto>>::createShared();
    page->offset = 1;
    page->limit = 2;
    page->count = items->size();
    page->items = items;

    return page;

}