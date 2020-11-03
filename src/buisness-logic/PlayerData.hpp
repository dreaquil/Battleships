//
// Created by david on 02/11/2020.
//

#ifndef BATTLESHIPS_PLAYERDATA_HPP
#define BATTLESHIPS_PLAYERDATA_HPP

#include <string>
#include <memory>

#include "PlayerShipStore.hpp"
#include "Peg.hpp"
#include "dto/PlayerShipPositionsDto.hpp"
#include "dto/AddPlayerDto.hpp"

namespace Battleships {

    class PlayerData {
    public:

        PlayerData() = delete;
        PlayerData(const AddPlayerDto &dto);

        int id() const;
        std::string username() const;
        bool isSetup() const;
        void positionShips(const PlayerShipPositionsDto& dto);

    private:
        unsigned int _id;
        std::string _username;
        bool isPlayerOne;
        std::unique_ptr<PlayerShipStore> shipsStore;

        // IMPORTANT: correspond to pins places on opponent's board - *NOT* their own one.
        std::vector<Peg> guessPegs;
    };

}


#endif //BATTLESHIPS_PLAYERDATA_HPP
