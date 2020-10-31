//
// Created by david on 31/10/2020.
//

#ifndef BATTLESHIPS_GAMEDB_HPP
#define BATTLESHIPS_GAMEDB_HPP

#include "dto/GameDto.hpp"
#include "oatpp-sqlite/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * GameDb client definitions.
 */
class GameDb : public oatpp::orm::DbClient {
public:

    GameDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
            : oatpp::orm::DbClient(executor)
    {}

    QUERY(createGame,
          "INSERT INTO games"
          "(status) VALUES "
          "(:game.status);",
          PARAM(oatpp::Object<GameDto>, game))

    QUERY(getGameById,
          "SELECT * FROM games WHERE id=:id;",
          PARAM(oatpp::Int32, id))

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //BATTLESHIPS_GAMEDB_HPP
