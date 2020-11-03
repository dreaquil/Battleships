//
// Created by david on 03/11/2020.
//

#include "GameplayController.hpp"

bool Battleships::GameplayController::isPlayer1Setup() const {
    return m_p1LowerBoard.isSetup();
}

bool Battleships::GameplayController::isPlayer2Setup() const {
    return m_p2LowerBoard.isSetup();
}

void Battleships::GameplayController::positionPlayer1Ships(const PlayerShipPositionsDto &dto) {
    m_p1LowerBoard.positionShips(dto);
}

void Battleships::GameplayController::positionPlayer2Ships(const PlayerShipPositionsDto &dto) {
    m_p2LowerBoard.positionShips(dto);
}

