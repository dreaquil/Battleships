//
// Created by david on 03/11/2020.
//

#include "Peg.hpp"
#include "OpponentBoard.hpp"

std::vector<Battleships::Peg> Battleships::OpponentBoard::pegs() const { return playerBoardForOpponent.pegs(); }
