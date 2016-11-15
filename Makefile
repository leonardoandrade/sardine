clean:
    rm *.o sardine

build: sardine.o
    gcc -c -o sardine.o sardine.c
    gcc -o sardine.o

all: build