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


bool isWhite(PIECE piece) {
    return (piece == WHITE_KING || piece == WHITE_QUEEN || piece == WHITE_ROOK
            || piece == WHITE_BISHOP || piece == WHITE_BISHOP || piece == WHITE_KNIGHT || piece == WHITE_PAWN);
}

void addPieceToPosition(Position * position, PIECE pieceToAdd, SQUARE square) {
    if (isWhite(pieceToAdd) && position->firstWhite == NULL) {
        position->firstWhite = makePiece(pieceToAdd, square);
        return;
    }
    if (!isWhite(pieceToAdd) && position->firstBlack == NULL) {
        position->firstBlack = makePiece(pieceToAdd, square);
        return;
    }

    Piece *piece = isWhite(pieceToAdd) ? position->firstWhite : position->firstBlack;

	while(1) {
		if(piece->next == NULL) {
			piece->next = makePiece(pieceToAdd, square);
			return;
		}
		piece = piece->next;
	}
}

int countWhitePieces(Position * position) {
    int count = 0;
    Piece * p = position->firstWhite;
    while(p != NULL) {
        count ++;
        p = p->next;
    }
    return count;
}

int countBlackPieces(Position * position) {
    int count = 0;
    Piece * p = position->firstBlack;
    while(p != NULL) {
        count ++;
        p = p->next;
    }
    return count;
}

int countPiecesOfPosition(Position * position) {
	return countWhitePieces(position) + countBlackPieces(position);
}

void setWhiteToMove(Position * position) {
    position->flags |= 0x1;
}

void setBlackToMove(Position * position) {
    position->flags |= 0x0;
}

bool isWhiteToMove(Position * position) {
    return position->flags & 0x01;
}

void setWhiteKingSideCastle(Position * position) {
	position->flags |= 1 << 2;
}

void setWhiteQueenSideCastle(Position * position) {
	position->flags |= 1 << 3;
}

void setBlackKingSideCastle(Position * position) {
	position->flags |= 1 << 4;
}

void setBlackQueenSideCastle(Position * position) {
	position->flags |= 1 << 5;
}

bool isWhiteKingSideCastle(Position * position) {
	return position->flags & (1 << 2);
}

bool isWhiteQueenSideCastle(Position * position) {
	return position->flags & (1 << 3);
}

bool isBlackKingSideCastle(Position * position) {
	return position->flags & (1 << 4);
}

bool isBlackQueenSideCastle(Position * position) {
	return position->flags & (1 << 5);
}
