//
// Created by david on 02/11/2020.
//

#ifndef BATTLESHIPS_PLAYERDATA_HPP
#define BATTLESHIPS_PLAYERDATA_HPP

#include <string>

namespace Battleships {

    class PlayerData {
    public:

        PlayerData() = delete;
        PlayerData(const std::string& username);
        std::string username() const;

    private:
        std::string _username;
        bool isPlayerOne;
    };

}


#endif //BATTLESHIPS_PLAYERDATA_HPP
