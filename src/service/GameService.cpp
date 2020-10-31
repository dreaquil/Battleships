
#include "GameService.hpp"

oatpp::Object<GameDto> GameService::createGame(const oatpp::Object<GameDto>& dto) {

  auto dbResult = m_database->createGame(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto gameId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

  OATPP_LOGD("AAA", "new gameId=%d", gameId);

  return getGameById((v_int32) gameId);

}

oatpp::Object<GameDto> GameService::getGameById(const oatpp::Int32& id, const std::shared_ptr<oatpp::orm::Connection>& connection) {

    auto dbResult = m_database->getGameById(id, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Game not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<GameDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}