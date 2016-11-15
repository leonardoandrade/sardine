/** 
 * Helper tools to print board and help debug operations
 */

#include "../board/definitions.h"
#include "../board/board.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
	U64 position = 0;
	char *p;
	unsigned long long bit_to_set = strtol(argv[1], &p, 10);
	printf("--> %lu (%llu)\n", sizeof (U64), bit_to_set);	
	position |= (1 << bit_to_set);
	U64 flags = 0;
	Piece piece = (Piece) {.position = position, .type = BLACK_BISHOP, .next = NULL};
	Board board = (Board) {.first = piece, .flags = flags};
	dump_board(board);
}