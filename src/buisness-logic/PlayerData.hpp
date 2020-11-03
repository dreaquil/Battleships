//
// Created by david on 02/11/2020.
//

#ifndef BATTLESHIPS_PLAYERDATA_HPP
#define BATTLESHIPS_PLAYERDATA_HPP

#include <string>
#include <memory>

#include "PlayerShipStore.hpp"
#include "dto/PlayerShipPositionsDto.hpp"
#include "LowerBoard.hpp"
#include "dto/AddPlayerDto.hpp"
#include "UpperBoard.hpp"

namespace Battleships {

    class PlayerData {
    public:

        PlayerData() = delete;
        PlayerData(const AddPlayerDto &dto);

        int id() const;
        std::string username() const;

        LowerBoard& lowerBoard();
        const LowerBoard& lowerBoard() const;

        UpperBoard& upperBoard();
        const UpperBoard& upperBoard() const;

    private:
        unsigned int _id;
        std::string _username;
        bool isPlayerOne;
        LowerBoard m_lowerBoard;
        UpperBoard m_upperBoard;
    };

}


#endif //BATTLESHIPS_PLAYERDATA_HPP
