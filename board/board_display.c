#include <string.h>
#include <stdio.h>
#include "definitions.h"
#include "board.h"

#define EMPTY_SQUARE '*'
#define OCCUPIED_SQUARE 'X'

void dump_byte(char c) {
	char str[17];
	memset(str, ' ',17);
	str[0]  = c & 0x01 ? OCCUPIED_SQUARE : EMPTY_SQUARE;
	str[2]  = c & 0x02 ? OCCUPIED_SQUARE : EMPTY_SQUARE;
	str[4]  = c & 0x04 ? OCCUPIED_SQUARE : EMPTY_SQUARE;
	str[6]  = c & 0x08 ? OCCUPIED_SQUARE : EMPTY_SQUARE;
	str[8]  = c & 0x10 ? OCCUPIED_SQUARE : EMPTY_SQUARE;
	str[10] = c & 0x20 ? OCCUPIED_SQUARE : EMPTY_SQUARE;
	str[12] = c & 0x40 ? OCCUPIED_SQUARE : EMPTY_SQUARE;
	str[14] = c & 0x80 ? OCCUPIED_SQUARE : EMPTY_SQUARE;
	str[16] = '\0';
	printf("%s\n", str);
}

void dump_piece(Piece piece) {
	U64 bit_board = piece.position;
	printf("Board %llx (%lld):\n", bit_board, bit_board);
	for(int i = 0; i < 8; i++) {
		char c = bit_board >> (8 * i);
		dump_byte(c);
	}
}

void dump_board(Board board) { 
	dump_u64(board.first);
}