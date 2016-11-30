FLAGS = -g -Wall
CC=gcc

clean:
	rm -f */*.o sardine print_board

sardine: sardine.c
	$(CC) $(FLAGS) -c -o sardine.o sardine.c
	$(CC) -o sardine.o

position: position/position.c position/position.o
	$(CC) $(FLAGS) -c -o position/position.o position/position.c 

fen: position/fen.c
	$(CC) $(FLAGS) -c -o position/fen.o position/fen.c 

board_display: position/board_display.c
	$(CC) $(FLAGS) -c -o position/board_display.o position/board_display.c 

print_board: tools/print_board.c position/position.o board_display fen
	$(CC) $(FLAGS) -o print_board tools/print_board.c position/position.o position/board_display.o position/fen.o

unity: vendor/unity/unity.c
	$(CC) $(FLAGS) -c -o vendor/unity/unity.o vendor/unity/unity.c

test: test/test.c position fen
	$(CC) $(FLAGS) -o test_all test/test.c position/position.o position/board_display.o position/fen.o vendor/unity/unity.o

all: print_board
