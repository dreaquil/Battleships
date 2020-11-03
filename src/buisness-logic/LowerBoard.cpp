//
// Created by david on 03/11/2020.
//

#include <algorithm>
#include "Peg.hpp"
#include "LowerBoard.hpp"

Battleships::Peg::PlacementResult Battleships::LowerBoard::placePeg(Battleships::Peg p) {

    if (!p.coordinate.isValid())
        return Peg::PlacementResult::NOT_INSERTED_INVALID_COORDINATE;

    if (std::any_of(_pegs.begin(),_pegs.end(),[&p](const Peg& o){return p.coordinate==o.coordinate;}))
        return Peg::PlacementResult::NOT_INSERTED_PEG_ALREADY_PLACED;

    _pegs.push_back(p);

    return Peg::PlacementResult::INSERTED;
}

std::vector<Battleships::Peg> Battleships::LowerBoard::pegs() const { return _pegs; }

bool Battleships::LowerBoard::isSetup() const { return shipsStore ? true : false; }

void Battleships::LowerBoard::positionShips(const PlayerShipPositionsDto &dto) {
    shipsStore = std::make_unique<PlayerShipStore>(dto);
}