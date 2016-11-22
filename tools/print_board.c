/** 
 * Helper tools to print board and help debug operations
 */

#include "../board/definitions.h"
#include "../board/board.h"
#include "../board/board_display.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
	Board * board = makeBoard();
	addPieceToBoard(board, BLACK_BISHOP, F3);
	addPieceToBoard(board, WHITE_KING, E1);
	addPieceToBoard(board, BLACK_KING, E8);
	dumpBoard(board);
}