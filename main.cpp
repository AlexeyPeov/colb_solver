#include <iostream>

#include "Game.h"

int main() {

    std::vector<Colb> colbs = {
            Colb(Color(DARK_WHITE),Color(GREEN),Color(DARK_RED),Color(PURPLE)),
            Colb(Color(PURPLE),Color(BLUE),Color(DARK_RED),Color(DARK_GREEN)),
            Colb(Color(ORANGE),Color(WHITE),Color(ORANGE),Color(DARK_GREEN)),
            Colb(Color(BLUE),Color(GREEN),Color(DARK_BLUE),Color(RED)),
            Colb(Color(PINK),Color(PURPLE),Color(YELLOW),Color(RED)),
            Colb(Color(YELLOW),Color(DARK_GREEN),Color(YELLOW),Color(GREEN)),
            Colb(Color(DARK_BLUE),Color(DARK_GREEN),Color(BLUE),Color(DARK_BLUE)),
            Colb(Color(PURPLE),Color(ORANGE),Color(WHITE),Color(ORANGE)),
            Colb(Color(YELLOW),Color(DARK_BLUE),Color(DARK_WHITE),Color(PINK)),
            Colb(Color(PINK),Color(DARK_WHITE),Color(GREEN),Color(BLUE)),
            Colb(Color(RED),Color(DARK_RED),Color(DARK_WHITE),Color(RED)),
            Colb(Color(WHITE),Color(WHITE),Color(DARK_RED),Color(PINK)),
            Colb(),
            Colb()
    };





    Game game(colbs);
    auto str = game.solve();

    for(auto& s : str)
        std::cout << s;
    return 0;
}
