//
// Created by david on 01/11/2020.
//

#ifndef BATTLESHIPS_PLAYERSERVICE_HPP
#define BATTLESHIPS_PLAYERSERVICE_HPP

#include "db/GameStateDbClient.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class PlayerService {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<GameStateDbClient>, m_database); // Inject database component
public:

    oatpp::Object<PlayerDto> createPlayer(const oatpp::Object<PlayerDto>& dto);
    oatpp::Object<PlayerDto> getPlayerById(const oatpp::Int32& id, const std::shared_ptr<oatpp::orm::Connection>& connection = nullptr);
    oatpp::Object<PageDto<oatpp::Object<PlayerDto>>> getAllPlayers();

};

#endif //BATTLESHIPS_PLAYERSERVICE_HPP
