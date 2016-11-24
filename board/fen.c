#include "fen.h"
#include <string.h>
#include <stdio.h>


void  processPiecesFragment(Board * board, char * fragment) {
	char * row_str = NULL;
	int row = 0;
	row_str = strtok(fragment, "/");
	while(row_str != NULL) {
		row_str = strtok(NULL, "/");
		if(row_str == NULL) {
			break;
		}
		row++;
		for(int i=0; i<strlen(row_str); i++) {
			printf("%c", row_str[i]);
		}
		printf("\n");

		//TODO: update the board
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