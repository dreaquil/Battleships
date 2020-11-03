cmake_minimum_required(VERSION 3.1)
project(Battleships)

set(CMAKE_CXX_STANDARD 17)

add_library(battleships-lib
        src/controller/StaticController.hpp
        src/controller/UserController.hpp
        src/db/GameStateDbClient.hpp
        src/dto/PageDto.hpp
        src/dto/GameDto.hpp
        src/dto/StatusDto.hpp
        src/dto/UserDto.hpp
        src/service/UserService.cpp
        src/service/UserService.hpp
        src/service/SessionManagementService.cpp
        src/service/SessionManagementService.hpp
        src/AppComponent.hpp
        src/DatabaseComponent.hpp
        src/SwaggerComponent.hpp
        src/ErrorHandler.cpp
        src/ErrorHandler.hpp
        src/controller/SessionManagementAPI.hpp
        src/dto/AddPlayerDto.hpp
        src/buisness-logic/Coordinate.hpp
        src/dto/ShipPositionDto.hpp
        src/buisness-logic/Row.hpp
        src/buisness-logic/Column.hpp
        src/buisness-logic/Coordinate.cpp
        src/buisness-logic/Ship.cpp
        src/buisness-logic/Ship.hpp
        src/dto/PlayerShipPositionsDto.hpp
        src/buisness-logic/PlayerShipStore.cpp
        src/buisness-logic/PlayerShipStore.hpp
        src/buisness-logic/PlayerData.cpp
        src/buisness-logic/PlayerData.hpp
        src/buisness-logic/SessionManager.cpp
        src/buisness-logic/SessionManager.hpp
        src/dto/SessionSummaryDto.hpp
        src/dto/PlayerGuessDto.hpp src/dto/GameRestartDto.hpp src/buisness-logic/CoordinateLine.cpp src/buisness-logic/CoordinateLine.hpp src/buisness-logic/Orientation.hpp src/buisness-logic/Peg.hpp)

## include directories

target_include_directories(battleships-lib PUBLIC src)


## link libs

find_package(oatpp          1.2.0 REQUIRED)
find_package(oatpp-swagger  1.2.0 REQUIRED)
find_package(oatpp-sqlite   1.2.0 REQUIRED)

target_link_libraries(battleships-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-swagger
        PUBLIC oatpp::oatpp-sqlite
)

add_definitions(
        ## define path to swagger-ui static resources folder
        -DOATPP_SWAGGER_RES_PATH="${OATPP_BASE_DIR}/bin/oatpp-swagger/res"

        ## SQLite databse file
        -DDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/db.sqlite"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    find_package(Threads REQUIRED)
    target_link_libraries(battleships-lib INTERFACE Threads::Threads ${CMAKE_DL_LIBS})
endif()

## add executables

add_executable(battleships-exe src/App.cpp)
target_link_libraries(battleships-exe battleships-lib)

add_executable(battleships-test
        test/tests.cpp
)
target_link_libraries(battleships-test battleships-lib)

enable_testing()
add_test(project-tests battleships-test)
