#ifndef BOARD_H
#define BOARD_H
#include "definitions.h"

typedef struct Piece {
    PIECE type;
    U64 position;
    struct Piece * next;  // linked list of pieces
} Piece;

typedef struct Board {
    U64 flags;
    Piece * first;
} Board;

char * to_fen(Board);

Board * makeBoard();

Piece * makePiece(PIECE, SQUARE);

void addPieceToBoard(Board *, PIECE, SQUARE);

void setCastlingPossibilitiesToBoard(Board *, int, int, int, int);

void setEnPassantColumnToBoard(Board *, int);

#endif