#include "definitions.h"
#include "position.h"
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


    if(pieceToAdd == //TODO)
	Piece * piece = position->firstWhite;
	
	while(1) {
		if(piece->next == NULL) {
			piece->next = makePiece(pieceToAdd, square);
			return;
		}
		piece = piece->next;
	}
}

int countPiecesOfPosition(Position * position) {
	int count = 0;
	Piece * p = position->first;
	while(p != NULL) {
		count ++;
		p = p->next;
	} 
	return count;
}


int countBlackPiecesOfPosition(Position * position) {
    int count = 0;
    Piece * p = position->first;
    while(p != NULL) {
        count ++;
        p = p->next;
    }
    return count;
}

