FLAGS = -g -Wall
CC=gcc
clean:
	rm -f */*.o sardine print_board

sardine: sardine.c
	$(CC) $(FLAGS) -c -o sardine.o sardine.c
	$(CC) -o sardine.o

board: board/board.c
	$(CC) $(FLAGS) -c -o board/board.o board/board.c 

fen: board/fen.c
	$(CC) $(FLAGS) -c -o board/fen.o board/fen.c 

board_display: board/board_display.c
	$(CC) $(FLAGS) -c -o board/board_display.o board/board_display.c 

print_board: tools/print_board.c board/board.o board_display fen
	$(CC) $(FLAGS) -o print_board tools/print_board.c board/board.o board/board_display.o board/fen.o

all: print_board
