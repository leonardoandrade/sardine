/** 
 * Helper tools to print board and help debug operations
 */

#include "../board/definitions.h"
#include "../board/board.h"
#include "../board/board_display.h"
#include "../board/fen.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
	if(argc != 2) {
		printf("USAGE:\n");
		printf("$%s <fen-position>\n", argv[0]);
		exit(0);
	}
	/*
	Board * board = makeBoard();
	addPieceToBoard(board, WHITE_KING, E1);
	addPieceToBoard(board, WHITE_PAWN, F2);
	addPieceToBoard(board, WHITE_PAWN, E2);
	addPieceToBoard(board, BLACK_PAWN, B7);
	addPieceToBoard(board, WHITE_KNIGHT, C5);
	addPieceToBoard(board, BLACK_KING, E8);
	addPieceToBoard(board, BLACK_BISHOP, F3);
	*/
	Board * board = fenToBoard(argv[1]);
	dumpBoard(board);
}