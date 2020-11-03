//
// Created by david on 02/11/2020.
//

#include <string>
#include <memory>
#include "PlayerData.hpp"
#include "PlayerShipStore.hpp"
#include "dto/AddPlayerDto.hpp"
#include "oatpp/orm/QueryResult.hpp"

Battleships::PlayerData::PlayerData(const AddPlayerDto &dto) :
    _username("-"), _id(0)
{
    _username = dto.userName->std_str();
    _id = dto.id;
}

int Battleships::PlayerData::id() const { return _id; }

std::string Battleships::PlayerData::username() const { return _username; }

bool Battleships::PlayerData::isSetup() const { return shipsStore ? true : false; }

void Battleships::PlayerData::positionShips(const PlayerShipPositionsDto &dto) {
    shipsStore = std::make_unique<PlayerShipStore>(dto);
}
