#include <iostream>

#include "Game.h"

int main() {

    std::vector<Colb> colbs = {
            Colb(Color(PURPLE),Color(GREEN),Color(GREEN),Color(DARK_RED)),
            Colb(Color(PINK),Color(DARK_GREEN),Color(DARK_WHITE),Color(YELLOW)),
            Colb(Color(BLUE),Color(BLUE),Color(DARK_RED),Color(GREEN)),
            Colb(Color(ORANGE),Color(YELLOW),Color(ORANGE),Color(PINK)),
            Colb(Color(PURPLE),Color(DARK_GREEN),Color(ORANGE),Color(BLUE)),
            Colb(Color(BLUE),Color(WHITE),Color(YELLOW),Color(DARK_GREEN)),
            Colb(Color(PURPLE),Color(RED),Color(WHITE),Color(DARK_RED)),
            Colb(Color(DARK_BLUE),Color(DARK_BLUE),Color(DARK_BLUE),Color(DARK_GREEN)),
            Colb(Color(PINK),Color(RED),Color(YELLOW),Color(WHITE)),
            Colb(Color(PURPLE),Color(RED),Color(DARK_WHITE),Color(DARK_WHITE)),
            Colb(Color(DARK_RED),Color(DARK_BLUE),Color(PINK),Color(RED)),
            Colb(Color(DARK_WHITE),Color(GREEN),Color(ORANGE),Color(WHITE)),
            Colb(),
            Colb(),
    };

/*    std::vector<Colb> colbs = {
            Colb(Color(PINK),Color(PINK),Color(PINK),Color(BRIGHT_GREEN)),
            Colb(Color(BRIGHT_GREEN),Color(BRIGHT_GREEN),Color(BRIGHT_GREEN),Color(PINK)),

            Colb(Color(BLUE),Color(BLUE),Color(YELLOW),Color(YELLOW)),
            Colb(Color(YELLOW),Color(YELLOW),Color(BLUE),Color(BLUE)),

            Colb(),
            Colb(),
    };*/

    Game game(colbs);
    auto str = game.solve();

    for(auto& s : str)
        std::cout << s;
    return 0;
}
