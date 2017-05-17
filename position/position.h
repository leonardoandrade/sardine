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

void Position_setWhiteToMove(Position *);

void Position_setBlackToMove(Position *);

bool Position_isWhiteToMove(Position *);

void Position_addPieceToPosition(Position *, PIECE, SQUARE);

void setCastlingPossibilitiesToPosition(Position *, int, int, int, int);

void setEnPassantColumnToPosition(Position *, int);

int Position_countPiecesOfPosition(Position * position);

int Position_countWhitePieces(Position * position);

int Position_countBlackPieces(Position * position);

void Position_setWhiteKingSideCastle(Position * position);

void Position_setWhiteQueenSideCastle(Position * position);

void  Position_setBlackKingSideCastle(Position * position);

void setBlackQueenSideCastle(Position* position) {
	position->flags |= 1 << 5;
}

bool Position_isWhiteKingSideCastle(Position * position);

bool Position_isWhiteQueenSideCastle(Position * position);

bool Position_isBlackKingSideCastle(Position * position);

bool Position_isBlackQueenSideCastle(Position * position);


#endif
