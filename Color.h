//
// Created by mi on 23.09.2023.
//

#ifndef COLB_SOLVER_COLOR_H
#define COLB_SOLVER_COLOR_H
#include <string>
struct Color{
    std::string info;
    Color(const std::string& color){
        info = color;
    }
    explicit Color() = default;
};
#endif //COLB_SOLVER_COLOR_H
