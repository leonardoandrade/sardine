clean:
	rm *.o sardine print_board

sardine: sardine.o
	gcc -g -c -o sardine.o sardine.c
	gcc -o sardine.o

board: board/board.o
	gcc -g -c -o board/board.o board/board.c 

print_board: tools/print_board.c board
	gcc -g -o print_board tools/print_board.c board/board.o

all: print_board
