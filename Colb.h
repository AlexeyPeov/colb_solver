//
// Created by mi on 23.09.2023.
//

#ifndef COLB_SOLVER_COLB_H
#define COLB_SOLVER_COLB_H

#include <vector>
#include <string>
#include "Color.h"

const int max_size = 4;

class Colb {
public:
    std::vector<Color> colors;

    bool solved = false;

    Colb(Color top, Color second, Color third, Color bottom){
        colors.emplace_back(bottom);
        colors.emplace_back(third);
        colors.emplace_back(second);
        colors.emplace_back(top);
    }

    static bool is_same_color(const Color &c1, const Color &c2){
        return c1 == c2;
    }
    Colb() = default;
};


#endif //COLB_SOLVER_COLB_H
