//
// Created by david on 03/11/2020.
//

#include "CoordinateLine.hpp"
#include "buisness-logic/Orientation.hpp"

Battleships::CoordinateLine::CoordinateLine(Battleships::Coordinate front, Battleships::Coordinate back)
{
    if (!front.isValid()) return;
    if (!back.isValid()) return;

    Orientation o = front.row()==back.row() ? Orientation::Horizontal :
                front.column() == back.column() ? Orientation::Vertical : Orientation::Invalid;

    if (o==Orientation::Invalid) return;

    // smells...
    while(true) {
        _data.push_back(front);

        if (front==back) return;

        switch (o) {
            case Orientation::Horizontal : {
                front.shiftRight(1);
                break;
            }
            case Orientation::Vertical : {
                front.shiftDown(1);
                break;
            }
        }
    }
}

bool Battleships::CoordinateLine::isValid() const { return _data.empty(); }
