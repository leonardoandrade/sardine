#ifndef BOARD_H
#define BOARD_H
#include "definitions.h"

typedef struct piece {
    PIECE type;
    U64 position;
    piece * next;  // linked list of pieces
}

typedef struct board {
    U64 flags;
    piece first;
};

char* to_fen(board);

void dump(board);

#endif