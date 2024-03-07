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
    PieceType playingType;

public:

    /**
     * Creates game for board with `board_size`*`board_size` size
     * @param board_size the width and height of the board
     */
    explicit Game(int board_size);

    /**
     * Returns board size
     * @return the size
     */
    int getBoardSize() const;

    /**
     * Gives a piecetype representing the type of the current player
     * @return the type
     */
    PieceType getPlayingType() const;

    /**
     * Returns all directions  to which player can go from piece at [x,y] in `board`
     * @param x horizontal position in board
     * @param y vertical position in board
     * @return the vector of possible directions
     */
    vector<MoveDirection> possibleMovesForPiece(int x, int y);

    /**
     * Returns a piecetype representing the type of the winner. Will be PieceType::NONE
     * when there is no winner yet.
     * @return the type
     */
    PieceType getWinner();


    /**
     * Moves piece at [x,y] in given direction
     * @param x the x position of selected piece
     * @param y the y position of selected piece
     * @param direction direction of the move
     */
    void doMove(int x, int y, MoveDirection direction);




    /**
     * toString method for the `board` vector
     */
    string toString();
};
