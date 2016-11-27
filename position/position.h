#ifndef BOARD_H
#define BOARD_H
#include "definitions.h"

typedef struct Piece {
    PIECE type;
    U64 position;
    struct Piece * next;  // linked list of pieces
} Piece;

typedef struct Position {
    U64 flags;
    Piece * first;
} Position;

char * to_fen(Position);

Position * makePosition();

Piece * makePiece(PIECE, SQUARE);

void addPieceToPosition(Position *, PIECE, SQUARE);

void setCastlingPossibilitiesToPosition(Position *, int, int, int, int);

void setEnPassantColumnToPosition(Position *, int);

int countPiecesOfPosition(Position * position);

#endif