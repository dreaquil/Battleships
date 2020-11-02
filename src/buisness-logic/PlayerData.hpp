//
// Created by david on 02/11/2020.
//

#ifndef BATTLESHIPS_PLAYERDATA_HPP
#define BATTLESHIPS_PLAYERDATA_HPP

#include <string>
#include <memory>

#include "PlayerShipStore.hpp"
#include "dto/PlayerShipPositionsDto.hpp"

namespace Battleships {

    class PlayerData {
    public:

        PlayerData() = delete;
        PlayerData(const std::string& username);

        std::string username() const;
        bool isSetup() const;
        void positionShips(const PlayerShipPositionsDto& dto);

    private:
        std::string _username;
        bool isPlayerOne;
        std::unique_ptr<PlayerShipStore> shipsStore;
    };

}


#endif //BATTLESHIPS_PLAYERDATA_HPP
