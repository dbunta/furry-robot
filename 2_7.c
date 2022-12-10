/*
    Exercise 2-7: Write a function invert(x,p,n) that returns x with the n
    bits that begin at position p inverted (i.e., 1 changed to 0 and vice versa), leaving
    the others unchanged.
*/

#include <stdio.h>

int invert(unsigned x, int p, int n, unsigned y);
int main() {
    int x = 234; //11101010
    unsigned t = ~0;
    printf("%d\n", t);
    // int p = 6;
    // int n = 3;
    // int y = 173; //10101101;
    // int r;
    // r = invert(x, p, n, y); //11011010 = 218
    // printf("%d\n", r);
}

/*

x = 1110 1010
p = 6
n = 3
ans =  10011010

unary of x:
11101010
00010101

shift left p
11111111
11111111000000
11101010000000
00000011101010
11101011101010


shift bitsofx right p - n
0000 0001


shift x right p + 1
0000 0001
shift x left n
0000 1000
or 
bits of x
0000 0001
=
0000 1001
shift left p + 1
1001 0000
or original x
1110 1010


getBits of unary:
0000 0001

shift inverted x bits to position to be inserted:
xBits = x << (p - n + 1)
0000 00110

xBits = ~xBits
0000 0001

get last n
xBits = 


1110 1010
0001 0000




1001


unary
shift left
shift right
and
or

all 0s or answer = answer
all 0s and answer = 0s
all 1s and answer = answer

*/



//

//  getbits of y 
//     = 
//     00000101
//     yBits = getBits(y, n, n-1);
    
//     shift new y left (p - n + 1)
//     =
//     01010000
//     11101010 (x)
//     yBits = y << (p - n + 1);

//     get bits of x for repopulation:
//     getBits(x, 6-3, 6-3+1)
//     00001010 
//     11101010 (x)
//     xBits = getBits(x, p-n, p-n+1);
    

//     shift x right p+1
//     00000001
//     11101010 (x)
//     x = x >> p+1;

//     shift x left p+1
//     10000000
//     11101010 (x)
//     x = x << p+1;

//     new x | new y
//     10000000
//     |
//     01010000
//     =
//     11010000
//     11101010 (x)
//     x = x | yBits;

//     new value | get bits of x
//     11010000
//     |
//     00001010 
//     =
//     11011010
//     x = x | xBits;

//     11001101