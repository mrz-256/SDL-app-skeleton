#pragma once

#include "Piece.h"
#include "MoveDirection.h"

#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using std::vector;
using std::string;
using std::stringstream;
using std::pair;

#include <iostream>

class Game {
private:
    vector<vector<Piece>> board;
    int board_size;
    bool light_playing;

public:

    /**
     * Creates game for board with `board_size`*`board_size` size
     * @param board_size the width and height of the board
     */
    explicit Game(int board_size);


    /**
     * Returns all directions  to which player can go from piece at [x,y] in `board`
     * @param x horizontal position in board
     * @param y vertical position in board
     * @return the vector of possible directions
     */
    vector<MoveDirection> possibleMovesForPiece(int x, int y);

    /**
     * Moves piece at [x,y] in given direction
     * @param x the x position of selected piece
     * @param y the y position of selected piece
     * @param direction direction of the move
     */
    void doMove(int x, int y, MoveDirection direction);



public:
    /**
     * toString method for the `board`
     */
    string toString();
};
