/** 
 * Helper tools to print position and help debug operations
 */

#include "../position/definitions.h"
#include "../position/position.h"
#include "../position/board_display.h"
#include "../position/fen.h"

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
	Position * position = makePosition();
	addPieceToPosition(position, WHITE_KING, E1);
	addPieceToPosition(position, WHITE_PAWN, F2);
	addPieceToPosition(position, WHITE_PAWN, E2);
	addPieceToPosition(position, BLACK_PAWN, B7);
	addPieceToPosition(position, WHITE_KNIGHT, C5);
	addPieceToPosition(position, BLACK_KING, E8);
	addPieceToPosition(position, BLACK_BISHOP, F3);
	*/
	Position * position = fenToPosition(argv[1]);
	dumpPosition(position);
}