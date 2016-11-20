#include "./definitions.h"
#include "./board.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * all operations related to the board itself
 */

Board * makeBoard() {
	Board * b =  malloc(sizeof(Board));
	b->first = NULL;
	b->flags = 0;
	return b;
}

Piece * makePiece(PIECE piece, SQUARE square) {
	U64 position = (U64) 1 << square;
	Piece * p = malloc(sizeof(piece));
	p->type = piece;
	p->position = position;
	p->next = NULL; 
	return p;
}

void addPieceToBoard(Board * board, PIECE piece, SQUARE square) {
	if(board->first == NULL) {
		board->first = makePiece(piece, square);
	}
}