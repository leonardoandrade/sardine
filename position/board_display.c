#include <string.h>
#include <stdio.h>
#include "definitions.h"
#include "position.h"
#include "board_display.h"

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
	U64 bit_position = piece->position;
	printf("Position %llx (%lld):\n", bit_position, bit_position);
	for(int i = 0; i < 8; i++) {
		char c = bit_position >> (8 * i);
		dump_byte(c);
	}
}

void writePieceToPosition(char positionView[8][8], Piece * piece) {
	U64 bit_position = piece->position;
	for(int i = 0; i < 8; i++) {
		char c = (char)(bit_position >> (8 * i));
		if(c & 0x01) {
			positionView[i][0] = pieceAsChar(piece);
		}
		else if(c & 0x02) {
			positionView[i][1] = pieceAsChar(piece);
		}
		else if(c & 0x04) {
			positionView[i][2] = pieceAsChar(piece);
		}
		else if(c & 0x08) {
			positionView[i][3] = pieceAsChar(piece);
		}
		else if(c & 0x10) {
			positionView[i][4] = pieceAsChar(piece);
		}
		else if(c & 0x20) {
			positionView[i][5] = pieceAsChar(piece);
		}
		else if(c & 0x40) {
			positionView[i][6] = pieceAsChar(piece);
		}
		else if(c & 0x80) {
			positionView[i][7] = pieceAsChar(piece);
		}
	}
}

void dumpFlags(Position * p) {
    char str[17];
	memset(str, ' ',16);
	str[16] = '\0';
    str[0] =  p->flags & 0x01   ? '1' : '0';
    str[1] =  p->flags & 0x02   ? '1' : '0';
    str[2] =  p->flags & 0x05   ? '1' : '0';
    str[3] =  p->flags & 0x08   ? '1' : '0';
    str[4] =  p->flags & 0x10   ? '1' : '0';
    str[5] =  p->flags & 0x20   ? '1' : '0';
    str[6] =  p->flags & 0x40   ? '1' : '0';
	str[7] =  p->flags & 0x80   ? '1' : '0';
	str[8] =  p->flags & 0x100  ? '1' : '0';
    str[9] =  p->flags & 0x200  ? '1' : '0';
	str[10] = p->flags & 0x400  ? '1' : '0';
    str[11] = p->flags & 0x800  ? '1' : '0';
	str[12] = p->flags & 0x1000 ? '1' : '0';
    str[13] = p->flags & 0x2000 ? '1' : '0';
	str[14] = p->flags & 0x4000 ? '1' : '0';
    str[15] = p->flags & 0x8000 ? '1' : '0';
    //str[16] = p->flags & 0x10000 ? '1' : '0';
    
    printf("Flags: %s\n", str);
}


void dumpPosition(Position * position) {
	char * to_move = Position_isWhiteToMove(position) ? "white" : " black";
	
    printf("%s to move:\n", to_move);


	char positionView [8][8];
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j< 8; j++) {
			positionView[i][j] = EMPTY_SQUARE;
		}
	}
	
	Piece * piece = position->firstWhite;
	while(piece != NULL) {
		writePieceToPosition(positionView, piece);
		piece = piece->next;
	}

    piece = position->firstBlack;
    while(piece != NULL) {
        writePieceToPosition(positionView, piece);
        piece = piece->next;
    }
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j< 8; j++) {
			printf("%c", positionView[i][j]);
		}
		printf("\n");
	}
    dumpFlags(position);
}
