//
// Created by david on 03/11/2020.
//

#ifndef BATTLESHIPS_COORDINATELINE_HPP
#define BATTLESHIPS_COORDINATELINE_HPP

#include <vector>
#include <iterator>
#include "buisness-logic/Coordinate.hpp"

namespace Battleships {

    class CoordinateLine {
    public:
        CoordinateLine(Coordinate front, Coordinate back);
        bool isValid() const;

        using const_iterator = const std::vector<Coordinate>::const_iterator;
        const_iterator begin() const;
        const_iterator end() const;

        bool overlaps(const CoordinateLine& other) const;

        unsigned int size() const;
    private:
        std::vector<Coordinate> _data;
    };

}

#endif //BATTLESHIPS_COORDINATELINE_HPP
