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
            || piece == WHITE_BISHOP || piece == WHITE_BISHOP || piece == WHITE_PAWN);
}

void addPieceToPosition(Position * position, PIECE pieceToAdd, SQUARE square) {

    Piece *piece = isWhite(pieceToAdd) ? position->firstWhite : position->firstBlack;

	while(1) {
		if(piece->next == NULL) {
			piece->next = makePiece(pieceToAdd, square);
			return;
		}
		piece = piece->next;
	}
}

int countWhitePiecesOfPosition(Position * position) {
    int count = 0;
    Piece * p = position->firstWhite;
    while(p != NULL) {
        count ++;
        p = p->next;
    }
    return count;
}

int countBlackPiecesOfPosition(Position * position) {
    int count = 0;
    Piece * p = position->firstBlack;
    while(p != NULL) {
        count ++;
        p = p->next;
    }
    return count;
}

int countPiecesOfPosition(Position * position) {
	return countWhitePiecesOfPosition(position) + countBlackPiecesOfPosition(position);
}


