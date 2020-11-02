//
// Created by david on 02/11/2020.
//

#include <vector>
#include "SessionManager.hpp"
#include "buisness-logic/PlayerData.hpp"

namespace Battleships {


    SessionManager::AddPlayerResponse SessionManager::addPlayer(const std::string &p) {

        switch (_state) {
            case GameState::WAITING_FOR_PLAYER : {

                switch (nPlayers()) {
                    case 0 : {
                        players.emplace_back(p);
                        return AddPlayerResponse::ACCEPTED_JOINED_SESSION_AS_PLAYER_1;
                    }
                    case 1 : {
                        _state = GameState::PLACING_SHIPS;
                        players.emplace_back(p);
                        return AddPlayerResponse::ACCEPTED_JOINED_SESSION_AS_PLAYER_2;
                    }
                    default : {
                        return AddPlayerResponse::UNSPECIFIED_ERROR;
                    }
                }
            }
            default : {
                return AddPlayerResponse::REJECTED_SESSION_IN_PROGRESS;
            }
        }
    }


    SessionManager::ShipPlacementResponse SessionManager::placeShips(unsigned int iPlayer, PlayerShipPositionsDto &dto) {

        switch (_state){
            case GameState::PLACING_SHIPS : {

                if (iPlayer>=nPlayers()) return ShipPlacementResponse::UNSPECIFIED_ERROR;

                PlayerShipStore shipsLayout(dto);
                if (!shipsLayout.isValid()) return ShipPlacementResponse::REJECTED_INVALID_LAYOUT;

                players[iPlayer].positionShips(dto);
                unsigned int iOpponent = iPlayer==0 ? 1 : 0;

                if (!players[iOpponent].isSetup()) return ShipPlacementResponse::ACCEPTED_UPDATED_SHIP_POSITIONS_WAITING_FOR_OTHER_PLAYER;

                _state = GameState::PLAYER_1_TURN;


                return ShipPlacementResponse::ACCEPTED_UPDATED_SHIP_POSITIONS_GAME_STARTING;
            }
            default : {
                return ShipPlacementResponse::REJECTED_CANNOT_PLACE_SHIPS_NOW;
            };
        }
    }


    unsigned int SessionManager::nPlayers() const {
        return players.size();
    }

}
