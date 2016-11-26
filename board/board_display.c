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

char pieceAsChar(Piece * piece) {
	switch(piece->type) {
		case WHITE_KING:
			return 'K';
		case BLACK_KING:
			return 'k';
		case WHITE_QUEEN:
			return 'Q';
		case BLACK_QUEEN:
			return 'q';	
		case WHITE_ROOK:
			return 'R';
		case BLACK_ROOK:
			return 'r';
		case WHITE_BISHOP:
			return 'B';
		case BLACK_BISHOP:
			return 'b';
		case WHITE_KNIGHT:
			return 'N';
		case BLACK_KNIGHT:
			return 'n';
		case WHITE_PAWN:
			return 'P';
		case BLACK_PAWN:
			return 'p';
		default:
			break;
	}
	return 'X';
}
void dump_piece(Piece * piece) {
	U64 bit_board = piece->position;
	printf("Board %llx (%lld):\n", bit_board, bit_board);
	for(int i = 0; i < 8; i++) {
		char c = bit_board >> (8 * i);
		dump_byte(c);
	}
}

void writePieceToBoard(char boardView[8][8], Piece * piece) {
	U64 bit_board = piece->position;
	printf("Board %llx (%lld):\n", bit_board, bit_board);
	for(int i = 0; i < 8; i++) {
		char c = bit_board >> (8 * i);
		if(c & 0x01) {
			boardView[i][0] = pieceAsChar(piece);
		}
		else if(c & 0x02) {
			boardView[i][1] = pieceAsChar(piece);
		}
		else if(c & 0x04) {
			boardView[i][2] = pieceAsChar(piece);
		}
		else if(c & 0x08) {
			boardView[i][3] = pieceAsChar(piece);
		}
		else if(c & 0x10) {
			boardView[i][4] = pieceAsChar(piece);
		}
		else if(c & 0x20) {
			boardView[i][5] = pieceAsChar(piece);
		}
		else if(c & 0x40) {
			boardView[i][6] = pieceAsChar(piece);
		}
		else if(c & 0x80) {
			boardView[i][7] = pieceAsChar(piece);
		}
	}
}

void dumpBoard(Board * board) {
	char boardView [8][8];
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j< 8; j++) {
			boardView[i][j] = EMPTY_SQUARE;
		}
	}
	

	Piece * piece = board->first;
	while(piece != NULL) {
		writePieceToBoard(boardView, piece);
		piece = piece->next;
	}
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j< 8; j++) {
			printf("%c", boardView[i][j]);
		}
		printf("\n");
	}
}