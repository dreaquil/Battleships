//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_COORDINATELINE_HPP
#define BATTLESHIPS_COORDINATELINE_HPP

#include <vector>
#include "buisness-logic/Coordinate.hpp"

namespace Battleships {

    class CoordinateLine {
    public:
        CoordinateLine(Coordinate front, Coordinate back);
        bool isValid() const;
        bool isEmpty() const;

        using const_iterator = const Coordinate*;
        const_iterator begin() const;
        const_iterator end() const;

    private:
        std::vector<Coordinate> _data;
    };

}

#endif //BATTLESHIPS_COORDINATELINE_HPP
