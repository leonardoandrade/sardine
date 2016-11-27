#include "./definitions.h"
#include "./position.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * all operations related to the position itself
 */

Position * makePosition() {
	Position * p =  malloc(sizeof(Position));
	p->first = NULL;
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

void addPieceToPosition(Position * position, PIECE pieceToAdd, SQUARE square) {
	if(position->first == NULL) {
		position->first = makePiece(pieceToAdd, square);
		return;
	}
	
	Piece * piece = position->first;
	
	while(1) {
		if(piece->next == NULL) {
			piece->next = makePiece(pieceToAdd, square);
			return;
		}
		piece = piece->next;
	}
}