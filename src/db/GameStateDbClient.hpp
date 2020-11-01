
#ifndef CRUD_USERDB_HPP
#define CRUD_USERDB_HPP

#include "dto/PlayerDto.hpp"
#include "dto/GameDto.hpp"
#include "dto/UserDto.hpp"
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

    QUERY(createUser,
          "INSERT INTO AppUser"
          "(username, email, password, role) VALUES "
          "(:user.username, :user.email, :user.password, :user.role);",
          PARAM(oatpp::Object<UserDto>, user))

    QUERY(updateUser,
          "UPDATE AppUser "
          "SET "
          " username=:user.username, "
          " email=:user.email, "
          " password=:user.password, "
          " role=:user.role "
          "WHERE "
          " id=:user.id;",
          PARAM(oatpp::Object<UserDto>, user))

    QUERY(getUserById,
          "SELECT * FROM AppUser WHERE id=:id;",
          PARAM(oatpp::Int32, id))

    QUERY(getAllUsers,
          "SELECT * FROM AppUser LIMIT :limit OFFSET :offset;",
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(deleteUserById,
          "DELETE FROM AppUser WHERE id=:id;",
          PARAM(oatpp::Int32, id))


    QUERY(createGame,
          "INSERT INTO games"
          "(status) VALUES "
          "(:game.status);",
          PARAM(oatpp::Object<GameDto>, game))

    QUERY(getGameById,
          "SELECT * FROM games WHERE id=:id;",
          PARAM(oatpp::Int32, id))

    QUERY(createPlayer,
          "INSERT INTO players"
          "(name) VALUES "
          "(:player.name);",
          PARAM(oatpp::Object<PlayerDto>, player))

    QUERY(getPlayerById,
          "SELECT * FROM players WHERE id=:id;",
          PARAM(oatpp::Int32, id))

    QUERY(getAllPlayers,
          "SELECT * FROM players")


};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //CRUD_USERDB_HPP
