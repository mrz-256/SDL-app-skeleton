#pragma once

/**
 * Used to store a direction of a move for a piece in game.
 * Values should be either (-1) or (+1) and nothing else.
 */
typedef struct MoveDirection {
    int horizontal;
    int vertical;

    MoveDirection(int h, int v) : horizontal(h), vertical(v)
    {}

    bool operator==(const MoveDirection &rhs) const
    {
        return horizontal == rhs.horizontal &&
                vertical == rhs.vertical;
    }

    bool operator!=(const MoveDirection &rhs) const
    {
        return !(rhs == *this);
    }

} MoveDirection;