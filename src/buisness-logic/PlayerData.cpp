//
// Created by david on 02/11/2020.
//

#include <memory>
#include "PlayerData.hpp"
#include "PlayerShipStore.hpp"

Battleships::PlayerData::PlayerData(const std::string &username) : _username(username)
{}

std::string Battleships::PlayerData::username() const { return username(); }

bool Battleships::PlayerData::isSetup() const { return shipsStore ? true : false; }

void Battleships::PlayerData::positionShips(const PlayerShipPositionsDto &dto) {
    shipsStore = std::make_unique<PlayerShipStore>(dto);
}
