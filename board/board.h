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
    Piece first;
} Board;

char * to_fen(Board);

void dump_board(Board);

#endif