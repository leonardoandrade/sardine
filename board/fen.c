#include "fen.h"
#include "board.h" 
#include <string.h>
#include <stdio.h>


int positionToPosition [8][8] = {
{A8, B8, C8, D8, E8, F8, G8, H8},
{A7, B7, C7, D7, E7, F7, G7, H7},
{A6, B6, C6, D6, E6, F6, G6, H6},
{A5, B5, C5, D5, E5, F5, G5, H5},
{A4, B4, C4, D4, E4, F4, G4, H4},
{A3, B3, C3, D3, E3, F3, G3, H3},
{A2, B2, C2, D2, E2, F2, G2, H2},
{A1, B1, C1, D1, E1, F1, G1, H1}
};

char pieceChars[12] = {'K', 'k', 'Q', 'q', 'R', 'r', 'B', 'b', 'N', 'n', 'P', 'p'};
PIECE pieceNames[12] = {WHITE_KING, BLACK_KING, WHITE_QUEEN, BLACK_QUEEN, WHITE_ROOK, BLACK_ROOK, WHITE_BISHOP, 
BLACK_BISHOP, WHITE_KNIGHT, BLACK_KNIGHT, WHITE_PAWN, BLACK_PAWN};

PIECE charToPiece(char c) {
	for(int i = 0; i<12; i++) {
		if(pieceChars[i] == c) {
			return pieceNames[i];
		}
	}
	return 99;
}

void  processPiecesFragment(Board * board, char * fragment) {
	char * row_str = NULL;
	int row = 0;
	row_str = strtok(fragment, "/");
	while(row_str != NULL) {
		
		if(row_str == NULL) {
			break;
		}
		
		int column = 0;
		for(int i=0; i<strlen(row_str); i++) {
			char c = row_str[i];
			if(c >= '1' && c <= '8') {
				column += c - 48;
			}
			else {
				PIECE p = charToPiece(c);
				addPieceToBoard(board, p, positionToPosition[row][column]);
				column++;
			}
			//printf("%c", row_str[i]);
		}
		row++;
		row_str = strtok(NULL, "/");
		//printf("\n");
	}
}

Board * fenToBoard(char * fen) {
	printf("1-->%s\n", fen);
	char * first_fragment = strtok(fen, " ");
	printf("2-->%s\n", first_fragment);
	Board * board = makeBoard();
	processPiecesFragment(board, first_fragment);
	return board;
}