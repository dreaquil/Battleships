
#ifndef CRUD_USERDB_HPP
#define CRUD_USERDB_HPP

#include "dto/AddPlayerDto.hpp"
#include "dto/GameDto.hpp"
#include "oatpp-sqlite/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * GameStateDbClient client definitions.
 */
class GameStateDbClient : public oatpp::orm::DbClient {
public:

    GameStateDbClient(const std::shared_ptr<oatpp::orm::Executor>& executor)
            : oatpp::orm::DbClient(executor)
    {

        oatpp::orm::SchemaMigration migration(executor);
        migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/001_init.sql");
        // TODO - Add more migrations here.
        migration.migrate(); // <-- run migrations. This guy will throw on error.

        auto version = executor->getSchemaVersion();
        OATPP_LOGD("GameStateDbClient", "Migration - OK. Version=%d.", version);

    }

    QUERY(createPlayer,
          "INSERT INTO players"
          "(name) VALUES "
          "(:player.name);",
          PARAM(oatpp::Object<AddPlayerDto>, player))

    QUERY(getPlayerById,
          "SELECT * FROM players WHERE id=:id;",
          PARAM(oatpp::Int32, id))

    QUERY(getAllPlayers,
          "SELECT * FROM players")

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //CRUD_USERDB_HPP
