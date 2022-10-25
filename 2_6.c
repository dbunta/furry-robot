#include <stdio.h>

void binary(int n);
int getBits(unsigned x, int p, int n);

int getBits(unsigned x, int p, int n) {
    int t = p + 1 - n;
    int t2 = x >> t;
    int t3 = ~0;
    int t4 = t3 << n;
    int t5 = ~t5;

    printf("%d", t);
    putchar('\n');
    printf("%d", t2);
    putchar('\n');
    printf("%d", t3);
    putchar('\n');
    printf("%d", t4);
    putchar('\n');
    printf("%d", t5);

    return (x >> (p+1-n)) & ~(~0 << n);
}

int main() {
    getBits(0, 0, 0);

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