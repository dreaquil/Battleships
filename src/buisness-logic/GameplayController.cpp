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

std::vector<Battleships::Peg> Battleships::GameplayController::player1UpperBoardPegs() const {
    return m_p2LowerBoard.pegs();
}

std::vector<Battleships::Peg> Battleships::GameplayController::player1LowerBoardPegs() const {
    return m_p1LowerBoard.pegs();
}

std::vector<Battleships::Peg> Battleships::GameplayController::player2UpperBoardPegs() const {
    return m_p1LowerBoard.pegs();
}

std::vector<Battleships::Peg> Battleships::GameplayController::player2LowerBoardPegs() const {
    return m_p2LowerBoard.pegs();
}

