//
// Created by david on 02/11/2020.
//

#include "PlayerData.hpp"

Battleships::PlayerData::PlayerData(const std::string &username) : _username(username)
{}

std::string Battleships::PlayerData::username() const { return username(); }
