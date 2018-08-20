#include "definitions.h"
#include "position.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define FLAGS_START_EN_PASSANT 5
#define FLAGS_START_HALF_MOVE_CLOCK 8
#define FLAGS_START_FULL_MOVE_COUNT 16
#define TWO_BIT_MASK    0x3
#define THREE_BIT_MASK  0xE
#define ONE_BYTE_MASK   0xFFFF

void print_as_binary(U32 theNumber) {
    char str[33];
	memset(str, ' ',33);
	str[16] = '\0';
    str[0] =  theNumber & 0x01   ? '1' : '0';
    str[1] =  theNumber & 0x02   ? '1' : '0';
    str[2] =  theNumber & 0x04   ? '1' : '0';
    str[3] =  theNumber & 0x08   ? '1' : '0';
    str[4] =  theNumber & 0x10   ? '1' : '0';
    str[5] =  theNumber & 0x20   ? '1' : '0';
    str[6] =  theNumber & 0x40   ? '1' : '0';
	str[7] =  theNumber & 0x80   ? '1' : '0';
	str[8] =  theNumber & 0x100  ? '1' : '0';
    str[9] =  theNumber & 0x200  ? '1' : '0';
	str[10] = theNumber & 0x400  ? '1' : '0';
    str[11] = theNumber & 0x800  ? '1' : '0';
	str[12] = theNumber & 0x1000 ? '1' : '0';
    str[13] = theNumber & 0x2000 ? '1' : '0';
	str[14] = theNumber & 0x4000 ? '1' : '0';
    str[15] = theNumber & 0x8000 ? '1' : '0';
    //str[16] = p->flags & 0x10000 ? '1' : '0';
    
    printf("VALUE: %s\n", str);
}

/**
 * all operations related to the position itself
 */

Position * makePosition() {
	Position * p =  malloc(sizeof(Position));
	p->firstWhite = NULL;
    p->firstBlack = NULL;
    p->flags = 0;
	return p;
}

Piece * makePiece(PIECE piece, SQUARE square) {
	U64 position = (U64) 1 << square;
	Piece * p = malloc(sizeof(Piece));
	p->type = piece;
	p->position = position;
	p->next = NULL; 
	return p;
}


bool Piece_isWhite(PIECE piece) {
    return (piece == WHITE_KING || piece == WHITE_QUEEN || piece == WHITE_ROOK
            || piece == WHITE_BISHOP || piece == WHITE_BISHOP || piece == WHITE_KNIGHT || piece == WHITE_PAWN);
}

void Position_addPieceToPosition(Position * position, PIECE pieceToAdd, SQUARE square) {
    if (Piece_isWhite(pieceToAdd) && position->firstWhite == NULL) {
        position->firstWhite = makePiece(pieceToAdd, square);
        return;
    }

    if (!Piece_isWhite(pieceToAdd) && position->firstBlack == NULL) {
        position->firstBlack = makePiece(pieceToAdd, square);
        return;
    }

    Piece *piece = Piece_isWhite(pieceToAdd) ? position->firstWhite : position->firstBlack;

	while(1) {
		if(piece->next == NULL) {
			piece->next = makePiece(pieceToAdd, square);
			return;
		}
		piece = piece->next;
	}
}

int Position_countWhitePieces(Position * position) {
    int count = 0;
    Piece * p = position->firstWhite;
    while(p != NULL) {
        count ++;
        p = p->next;
    }
    return count;
}

int Position_countBlackPieces(Position * position) {
    int count = 0;
    Piece * p = position->firstBlack;
    while(p != NULL) {
        count ++;
        p = p->next;
    }
    return count;
}

int Position_countPiecesOfPosition(Position * position) {
	return Position_countWhitePieces(position) + Position_countBlackPieces(position);
}

void Position_setWhiteToMove(Position * position) {
    position->flags |= 0x1;
}

void Position_setBlackToMove(Position * position) {
    position->flags |= 0x0;
}

bool Position_isWhiteToMove(Position * position) {
    return position->flags & 0x01;
}

void Position_setWhiteKingSideCastle(Position * position) {
	position->flags |= 0x1 << 1;
}

void Position_setWhiteQueenSideCastle(Position * position) {
	position->flags |= 0x1 << 2;
}

void Position_setBlackKingSideCastle(Position * position) {
	position->flags |= 0x1 << 3;
}

void Position_setBlackQueenSideCastle(Position * position) {
	position->flags |= 0x1 << 4;
}

bool Position_isWhiteKingSideCastle(Position * position) {
	return position->flags & (0x1 << 1);
}

bool Position_isWhiteQueenSideCastle(Position * position) {
	return position->flags & (0x1 << 2);
}

bool Position_isBlackKingSideCastle(Position * position) {
	return position->flags & (0x1 << 3);
}

bool Position_isBlackQueenSideCastle(Position * position) {
	return position->flags & (0x1 << 4);
}

//En passant
void Position_setEnPassantColumn(Position * position, int column) {
    position->flags |= column << FLAGS_START_EN_PASSANT;
}

void Position_resetEnPassant(Position * position) {
    position->flags |= 0x00 << FLAGS_START_EN_PASSANT;
}

int Position_getEnPassantColumn(Position * position) {
    U32 mask = THREE_BIT_MASK << FLAGS_START_EN_PASSANT;
    print_as_binary(mask);
    return (position->flags & mask) >> FLAGS_START_EN_PASSANT;
}

//Half move clock
void Position_setHalfMoveClock(Position * position, int halfMoveClock) {
    position->flags |= halfMoveClock << FLAGS_START_HALF_MOVE_CLOCK;
    //position->flags |= (halfMoveClock >> 1) << (FLAGS_START_HALF_MOVE_CLOCK+1);
}

int Position_getHalfMoveClock(Position * position) {
    U32 mask = ONE_BYTE_MASK << FLAGS_START_HALF_MOVE_CLOCK;
    print_as_binary(mask);
    return (position->flags & mask) >> FLAGS_START_HALF_MOVE_CLOCK;
}

//Full move count
void Position_setFullMoveCount(Position * position, int fullMoveCount) {
    position->flags |= fullMoveCount << FLAGS_START_FULL_MOVE_COUNT;
}

int Position_getFullMoveCount(Position * position) {
    U64 mask = ONE_BYTE_MASK << FLAGS_START_FULL_MOVE_COUNT;
    return (position->flags & mask) >> FLAGS_START_FULL_MOVE_COUNT;
}
