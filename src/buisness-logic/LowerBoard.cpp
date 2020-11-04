//
// Created by david on 03/11/2020.
//

#include <algorithm>
#include "Peg.hpp"
#include "LowerBoard.hpp"


bool Battleships::LowerBoard::hasShipAt(Battleships::Coordinate coord) {

    const auto &ships = *shipsStore.get();

    for(const auto& ship : ships)
    {
        if (ship.isOccupying(coord)) return true;
    }

    return false;
}


Battleships::Peg::PlacementResult Battleships::LowerBoard::placePeg(Battleships::Peg p) {

    if (!p.coordinate.isValid())
        return Peg::PlacementResult::NOT_INSERTED_INVALID_PLACEMENT;

    if (std::any_of(_pegs.begin(),_pegs.end(),[&p](const Peg& o){return p.coordinate==o.coordinate;}))
        return Peg::PlacementResult::NOT_INSERTED_INVALID_PLACEMENT;

    _pegs.push_back(p);

    auto* pShip = shipsStore->getShipAt(p.coordinate);
    if (pShip)
    {
        pShip->hit();

        return pShip->isSunk() ? shipsStore->allSunk() ? Peg::PlacementResult::INSERTED_HIT_AND_SUNK_WIN_CONDITION :
                Peg::PlacementResult::INSERTED_HIT_AND_SUNK : Peg::PlacementResult::INSERTED_HIT;
    }

    return Peg::PlacementResult::INSERTED_MISS;
}

std::vector<Battleships::Peg> Battleships::LowerBoard::pegs() const { return _pegs; }

bool Battleships::LowerBoard::isSetup() const { return shipsStore ? true : false; }

void Battleships::LowerBoard::positionShips(const PlayerShipPositionsDto &dto) {
    shipsStore = std::make_unique<PlayerShipStore>(dto);
}

