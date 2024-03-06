#include "../../headers/logic/Game.h"

Game::Game(int board_size) : board_size(board_size)
{
    light_playing = true;
    board.resize(board_size, vector<Piece>(board_size, Piece(PieceType::NONE)));

    // fill first 3 rows with LIGHT PIECES
    for (int y = 0; y < 3; ++y)
    {
        for (int x = 0; x < board_size; ++x)
        {
            if ((x & 1) and (y & 1) or !(x & 1) and !(y & 1)) board[y][x] = Piece(PieceType::LIGHT);
        }
    }

    // fill last 3 rows with DARK PIECES
    for (int y = board_size-3; y < board_size; ++y)
    {
        for (int x = 0; x < board_size; ++x)
        {
            if ((x & 1) and (y & 1) or !(x & 1) and !(y & 1)) board[y][x] = Piece(PieceType::DARK);
        }
    }
}

vector<MoveDirection> Game::possibleMovesForPiece(int x, int y)
{
    // get the current piece
    Piece current = board[y][x];

    // empty cell can make no moves
    if (current.type == PieceType::NONE) return {};

    // the result
    vector<MoveDirection> output;

    // light moves 'down'(+1), while dark 'up'(-1)
    // king can do both
    vector<pair<int, int>> directions;
    if (current.type == PieceType::LIGHT or current.rank == PieceRank::KING)
    {
        directions.emplace_back(-1, 1);
        directions.emplace_back(1, 1);
    }
    if (current.type == PieceType::DARK or current.rank == PieceRank::KING)
    {
        directions.emplace_back(-1, -1);
        directions.emplace_back(1, -1);
    }

    for (auto [h, v]: directions)
    {
        int next_x = x + h;
        int next_y = y + v;

        // when the direction is invalid (outside board)
        if (next_x < 0 or next_x >= board_size or next_y < 0 or next_y >= board_size) continue;

        // get the piece
        Piece next = board[next_y][next_x];

        // if adjacent position is vacant, direction is valid
        if (next.type == PieceType::NONE)
        {
            output.emplace_back(h, v);
            continue;
        }

        // can't jump over your own pieces
        if (current.type == next.type) continue;


        // checking the next position in that direction to make a skip over
        next_x += h;
        next_y += v;

        // again check if position is valid
        if (next_x < 0 or next_x >= board_size or next_y < 0 or next_y >= board_size) continue;
        next = board[next_y][next_x];

        // if adjacent position is vacant, direction is valid
        if (next.type == PieceType::NONE)
        {
            output.emplace_back(h, v);
        }
    }
    return output;
}

void Game::doMove(int x, int y, MoveDirection direction)
{

}

string Game::toString()
{
    stringstream ss;
    for (int y = 0; y < board_size; ++y)
    {
        for (int x = 0; x < board_size; ++x)
        {
            switch (board[y][x].type)
            {
                case PieceType::NONE: ss << "[ ]";
                    break;
                case PieceType::LIGHT: ss << "[l]";
                    break;
                case PieceType::DARK: ss << "[d]";
                    break;
            }
        }
        ss << "\n";
    }
    return ss.str();
}
