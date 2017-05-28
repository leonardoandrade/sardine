#include <string.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long U64;


void print_as_binary(U64 theNumber) {
    char str[73];
    memset(str, ' ',73);
    int j=0;
    for(int i = 0; i<64; i++) {
        str[j] = theNumber & (int)powl(2, i) ? '1' : '0';
        if((i+1)%8 == 0) {
            j++;
            str[j] = '\n';
            j++;
        }
        else {
            j++;
        }
    }
    str[j] = '\0';
    printf("%s\n", str);
}

int main() {
    U64 theNumber = 0x0;
    int banana = 1;
    int position = 7;
    theNumber |= banana << position;
    
    U64 mask = 0xF << position; // the mask
    printf("number:\n");
    print_as_binary(theNumber);
    printf("mask:\n");
    print_as_binary(mask);

    int extractedNumber = (theNumber & mask) >> position;
    printf("extracted number: %d \n", extractedNumber);


}

