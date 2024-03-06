#pragma once

enum class PieceType {
    LIGHT = -1,
    NONE = 0,
    DARK = 1,
};

enum class PieceRank {
    MAN, KING
};

typedef struct Piece {
    PieceType type = PieceType::NONE;
    PieceRank rank = PieceRank::MAN;

    explicit Piece(PieceType type, PieceRank rank = PieceRank::MAN) : type(type), rank(rank)
    {}
} Piece;