#FLAGS = -g -Wall -coverage
FLAGS = -g -Wall

CC=clang

clean:
	rm -f */*.o bin/* */*.gcda */*.gcno

sardine: sardine.c
	$(CC) $(FLAGS) -c -o sardine.o sardine.c
	$(CC) -o sardine.o

position: position/position.c position/position.o
	$(CC) $(FLAGS) -c -o position/position.o position/position.c 

fen: position/fen.c position/fen.o
	$(CC) $(FLAGS) -c -o position/fen.o position/fen.c 

board_display: position/board_display.c position/board_display.o
	$(CC) $(FLAGS) -c -o position/board_display.o position/board_display.c 

print_board: tools/print_board.c position/position.o board_display fen
	$(CC) $(FLAGS) -o print_board tools/print_board.c position/position.o position/board_display.o position/fen.o

common: position/common.c
	$(CC) $(FLAGS) -c -o position/common.o position/common.c

unity: vendor/unity/unity.c
	$(CC) $(FLAGS) -c -o vendor/unity/unity.o vendor/unity/unity.c

test_fen: test/test_fen.c position fen common board_display
	$(CC) $(FLAGS) -o ./bin/test_fen test/test_fen.c position/position.o position/board_display.o position/fen.o vendor/unity/unity.o

test_all: test_fen

all: print_board
