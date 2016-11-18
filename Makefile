clean:
	rm *.o sardine print_board

sardine: sardine.o
	gcc -c -o sardine.o sardine.c
	gcc -o sardine.o

board: board/board.c
	gcc -c -o board/board.o board/board.c 

print_board: tools/print_board.c board
	gcc -o print_board tools/print_board.c board/board.o

all: print_board
