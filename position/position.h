#ifndef BOARD_H
#define BOARD_H
#include "definitions.h"
#include <stdbool.h>

typedef struct Piece {
    PIECE type;
    U64 position;
    struct Piece * next;  // linked list of pieces
} Piece;

typedef struct Position {
    U64 flags;
    Piece * firstWhite;
    Piece * firstBlack;
} Position;


/* Flags work like this:
 * pos | flag
 *   0 | white to move
 *   1 | white can 0-0
 *   2 | black can 0-0
 *   3 | white can 0-0-0
 *   4 | black can 0-0-0
 *   5 | TBA
*/

char * to_fen(Position);

Position * makePosition();

Piece * makePiece(PIECE, SQUARE);

void setWhiteToMove(Position *);

void setBlackToMove(Position *);

bool isWhiteToMove(Position *);

void addPieceToPosition(Position *, PIECE, SQUARE);

void setCastlingPossibilitiesToPosition(Position *, int, int, int, int);

void setEnPassantColumnToPosition(Position *, int);

int countPiecesOfPosition(Position * position);

int countWhitePieces(Position * position);

int countBlackPieces(Position * position);

void setWhiteKingSideCastle(Position * position);

void setWhiteQueenSideCastle(Position * position);

void setBlackKingSideCastle(Position * position);

void setBlackQueenSideCastle(Position * position);

bool isWhiteKingSideCastle(Position * position);

bool isWhiteQueenSideCastle(Position * position);

bool isBlackKingSideCastle(Position * position);

bool isBlackQueenSideCastle(Position * position);


#endif
