#include "definitions.h"
#include "position.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


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
	position->flags |= 1 << 2;
}

void Position_setWhiteQueenSideCastle(Position * position) {
	position->flags |= 1 << 3;
}

void Position_setBlackKingSideCastle(Position * position) {
	position->flags |= 1 << 4;
}


void Position_setBlackQueenSideCastle(Position * position) {
	position->flags |= 1 << 5;
}

bool Position_isWhiteKingSideCastle(Position * position) {
	return position->flags & (1 << 2);
}

bool Position_isWhiteQueenSideCastle(Position * position) {
	return position->flags & (1 << 3);
}

bool Position_isBlackKingSideCastle(Position * position) {
	return position->flags & (1 << 4);
}

bool Position_isBlackQueenSideCastle(Position * position) {
	return position->flags & (1 << 5);
}
