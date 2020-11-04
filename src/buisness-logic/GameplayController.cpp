//
// Created by david on 03/11/2020.
//

#include "GameplayController.hpp"
#include "Peg.hpp"

namespace {

    Battleships::GameplayController::GuessResponse translatePlacePegResponse(Battleships::Peg::PlacementResult pegRsp) {

        using namespace Battleships;
        switch (pegRsp) {
            case Peg::PlacementResult::INSERTED_HIT :
                return GameplayController::GuessResponse::ACCEPTED_HIT;
            case Peg::PlacementResult::INSERTED_HIT_AND_SUNK :
                return GameplayController::GuessResponse::ACCEPTED_HIT_AND_SUNK;
            case Peg::PlacementResult::INSERTED_HIT_AND_SUNK_WIN_CONDITION :
                return GameplayController::GuessResponse::ACCEPTED_HIT_AND_SUNK_WIN_CONDITION;
            case Peg::PlacementResult::INSERTED_MISS :
                return GameplayController::GuessResponse::ACCEPTED_MISS;
            case Peg::PlacementResult::NOT_INSERTED_INVALID_PLACEMENT :
                return GameplayController::GuessResponse::REJECTED_INVALID_COORDINATE;
        }
    }
}


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


Battleships::GameplayController::GuessResponse Battleships::GameplayController::handlePlayer1Guess(const Battleships::Coordinate &pos) {

    Peg p = m_p2LowerBoard.hasShipAt(pos) ? Peg(pos, Peg::Colour::RED) :  Peg(pos, Peg::Colour::WHITE);

    Peg::PlacementResult pegResult = m_p2LowerBoard.placePeg(p);
    return translatePlacePegResponse(pegResult);
}


std::vector<Battleships::Peg> Battleships::GameplayController::player2UpperBoardPegs() const {
    return m_p1LowerBoard.pegs();
}


std::vector<Battleships::Peg> Battleships::GameplayController::player2LowerBoardPegs() const {
    return m_p2LowerBoard.pegs();
}


Battleships::GameplayController::GuessResponse Battleships::GameplayController::handlePlayer2Guess(const Battleships::Coordinate &pos) {

    Peg p = m_p1LowerBoard.hasShipAt(pos) ? Peg(pos, Peg::Colour::RED) :  Peg(pos, Peg::Colour::WHITE);

    Peg::PlacementResult pegResult = m_p1LowerBoard.placePeg(p);
    return translatePlacePegResponse(pegResult);
}




