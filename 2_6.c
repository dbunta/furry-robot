/*
Write a function setbits(x,p,n,y) that returns x with the n
bits that begin at position p set to the rightmost n bits of y, leaving the other
bits unchanged.
*/

#include <stdio.h>

void binary(int n);
int getBits(unsigned x, int p, int n);
int setBits(unsigned x, int p, int n, unsigned y);

int getBits(unsigned x, int p, int n) {
    //p=3
    //n=3
    //11001000
    //01100100
    //&
    //00000111
    //00000100

    int t = p + 1 - n;
    int t2 = x >> t;
    int t3 = ~0;
    int t4 = t3 << n;
    int t5 = ~t5;
    int t6 = t2 & t5;

    printf("%d", t);
    putchar('\n');
    printf("%d", t2);
    putchar('\n');
    printf("%d", t3);
    putchar('\n');
    printf("%d", t4);
    putchar('\n');
    printf("%d", t5);
    putchar('\n');
    printf("%d", t6);

    return (x >> (p+1-n)) & ~(~0 << n);
}

int main() {

    int t = 1 & 16;
    printf("%d", t);

    //getBits(0, 0, 0);

    // int yes, no, cancel, buttons;
    // yes = 1;
    // no = 2;
    // cancel = 4;

    // buttons = yes | cancel;

    // int isButton;
    // isButton = no & buttons;

    // binary(isButton);

    // putchar('\n');
    // printf("%d", isButton);
}

void binary(int n) {

    int a[10], i;
    for (i = 0; n > 0; i++) {
        a[i]=n%2;    
        n=n/2;
        printf("%d", a[i]);
    }
    
}

int setBits(unsigned x, int p, int n, unsigned y) {
    unsigned xBits, yBits;
    yBits = getBits(y, n, n-1);
    yBits = y << (p - n + 1);
    xBits = getBits(x, p-n, p-n+1);
    x = x >> p+1;
    x = x << p+1;
    x = x | yBits;
    x = x | xBits;
    return x;
    /*
    x = 11101010
    y = 10101101
    p = 6
    n = 3
    final answer
    =
    11011010
    11101010 (x)
    


    getbits of y 
    = 
    00000101
    yBits = getBits(y, n, n-1);
    
    shift new y left (p - n + 1)
    =
    01010000
    11101010 (x)
    yBits = y << (p - n + 1);

    get bits of x for repopulation:
    getBits(x, 6-3, 6-3+1)
    00001010 
    11101010 (x)
    xBits = getBits(x, p-n, p-n+1);
    

    shift x right p+1
    00000001
    11101010 (x)
    x = x >> p+1;

    shift x left p+1
    10000000
    11101010 (x)
    x = x << p+1;

    new x | new y
    10000000
    |
    01010000
    =
    11010000
    11101010 (x)
    x = x | yBits;

    new value | get bits of x
    11010000
    |
    00001010 
    =
    11011010
    x = x | xBits;

    11001101
    */
    unsigned j = getBits(y, n-1, n);
    
    unsigned k = ((x >> n) << n) | j;

    return k;
    /*
    11001010
    00011001
    11001000
    |
    00000101
    11111111

    */

}