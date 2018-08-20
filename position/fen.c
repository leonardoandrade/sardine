#include "fen.h"
#include "position.h"
#include "common.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


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
    panic("piece is not recognized");
    return (PIECE) NULL;
}

void Fen_processPiecesFragment(Position * position, char * fragment) {
	char * row_str = NULL;
	int row = 0;
	row_str = strtok(fragment, "/");
	while(row_str != NULL) {

		int column = 0;
		for(int i=0; i<strlen(row_str); i++) {
			char c = row_str[i];
			if(c >= '1' && c <= '8') {
				column += c - 48;
			}
			else {
				PIECE p = charToPiece(c);
				Position_addPieceToPosition(position, p, positionToPosition[row][column]);
				column++;
			}
			//printf("%c", row_str[i]);
		}
		row++;
		row_str = strtok(NULL, "/");
		//printf("\n");
	}
}

void Fen_processCastling(Position * position, char * fragment) {
	for(int i = 0; i<strlen(fragment); i++) {
		if(fragment[i]=='K') Position_setWhiteKingSideCastle(position);
		else if(fragment[i]=='k') Position_setWhiteQueenSideCastle(position);
		else if(fragment[i]=='Q') Position_setBlackKingSideCastle(position);
		else if(fragment[i]=='q') Position_setBlackQueenSideCastle(position);
	}
}

void Fen_processEnPassant(Position * position, char * fragment) {
	//use only the column, the square can be inferred who is to move
	char column = fragment[0];

	int columnValue = 0;
	if(column >= 'a' && column <= 'h') {
		columnValue = column - 96; //from 1 to 8;
	}

	if(columnValue != 0) {
		Position_setEnPassantColumn(position, columnValue);
	} else {
		Position_resetEnPassant(position);
	}
}

void Fen_processHalfMoveClock(Position * position, char * fragment) {
	int halfMoveClock = atoi(fragment);
	Position_setHalfMoveClock(position, halfMoveClock);
}

void Fen_processMoveCount(Position * position, char * fragment) {
	int moveCount = atoi(fragment);
	Position_setFullMoveCount(position, moveCount);
}


Position * Fen_fenToPosition(char * fen) {

	Position * position = makePosition();
	//1. process pieces positions
	char * first_fragment = strtok(fen, " ");
	printf("1st fragment -->%s\n", first_fragment);

	//2. side to move
	char * second_fragment = strtok(NULL, " ");
	printf("2nd fragment -->%s\n", second_fragment);

	if(second_fragment[0] == 'w') {
		Position_setWhiteToMove(position);
	}
	else if(second_fragment[0] == 'b') {
		Position_setBlackToMove(position);
	}
	else {
		panic("Error parsing FEN: turn to move is not 'w' or 'b'");
	}


	//3. castling
	char * third_fragment = strtok(NULL, " ");
	printf("3rd fragment -->%s\n", third_fragment);
	Fen_processCastling(position, third_fragment);

	//4. en passant
	char * fourth_fragment = strtok(NULL, " ");
	printf("4th fragment -->%s\n", third_fragment);
	Fen_processEnPassant(position, fourth_fragment);


	//5. half move clock
	char * fifth_fragment = strtok(NULL, " ");
	printf("5th fragment -->%s\n", fifth_fragment);
	Fen_processHalfMoveClock(position, fifth_fragment);

	//6. half move clock
	char * sixth_fragment = strtok(NULL, " ");
	printf("6th fragment -->%s\n", sixth_fragment);

	Fen_processMoveCount(position, sixth_fragment);

	Fen_processPiecesFragment(position, first_fragment);

	dumpPosition(position);
	return position;
}
