//
// Created by david on 03/11/2020.
//

#include <algorithm>
#include "Peg.hpp"
#include "PlayerShipsBoard.hpp"

Battleships::Peg::PlacementResult Battleships::PlayerShipsBoard::placePeg(Battleships::Peg p) {

    if (!p.coordinate.isValid())
        return Peg::PlacementResult::NOT_INSERTED_INVALID_COORDINATE;

    if (std::any_of(_pegs.begin(),_pegs.end(),[&p](const Peg& o){return p.coordinate==o.coordinate;}))
        return Peg::PlacementResult::NOT_INSERTED_PEG_ALREADY_PLACED;

    _pegs.push_back(p);

    return Peg::PlacementResult::INSERTED;
}

std::vector<Battleships::Peg> Battleships::PlayerShipsBoard::pegs() const { return _pegs; }
