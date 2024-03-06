#include <iostream>
#include "headers/logic/Game.h"

int main()
{
    Game game(8);
    std::cout << game.toString() << "\n";

    for(auto& d : game.possibleMovesForPiece(1, 5))
    {
        std::cout << "[" << d.horizontal << ";" << d.vertical << "]";
    }

    return 0;
}
