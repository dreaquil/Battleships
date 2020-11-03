//
// Created by david on 03/11/2020.
//

#include <algorithm>
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

Battleships::CoordinateLine::const_iterator Battleships::CoordinateLine::begin() const { return _data.begin(); }

Battleships::CoordinateLine::const_iterator Battleships::CoordinateLine::end() const { return _data.end(); }

bool Battleships::CoordinateLine::overlaps(Battleships::CoordinateLine) const {

    this->sort();

    return false;
}

bool Battleships::CoordinateLine::isSorted() const { return std::is_sorted(_data.begin(),_data.end()); }

void Battleships::CoordinateLine::sort() const {
    if(!this->isSorted())
    {
        //std::sort(_data.begin(),_data.end());
    }
}

