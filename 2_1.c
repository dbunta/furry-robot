#include <stdio.h>
#include <limits.h>
#include <float.h>

int computeUnsignedSize(int bits);
int computeSignedSize(int bits);

int main() {
    //signed char
    printf("%s%d", "signed char: ", CHAR_MIN);
    printf("%s%d", " to ", CHAR_MAX);

    putchar('\n');

    //unsigned char
    printf("%s%d", "unsigned char: ", 0);
    printf("%s%d", " to ", UCHAR_MAX);

    putchar('\n');

    //signed int
    printf("%s%d", "signed int: ", INT_MIN);
    printf("%s%d", " to: ", INT_MAX);

    putchar('\n');

    //unsigned int
    printf("%s%d", "unsigned int: ", 0);
    printf("%s%u", " to ", UINT_MAX);

    putchar('\n');

    //signed short
    printf("%s%d", "signed short: ", SHRT_MIN);
    printf("%s%d", " to ", SHRT_MAX);

    putchar('\n');

    //unsigned short
    printf("%s%d", "unsigned short: ", 0);
    printf("%s%u", " to ", USHRT_MAX);

    putchar('\n');
    
    //signed long
    printf("%s%ld", "signed long: ", LONG_MIN);
    printf("%s%ld", " to ", LONG_MAX);

    putchar('\n');

    //unsigned long
    printf("%s%d", "unsigned long: ", 0);
    printf("%s%lu", " to ", ULONG_MAX);
    
    putchar('\n');

    int charUnsigned = computeUnsignedSize(CHAR_BIT);
    int shortUnsigned = computeUnsignedSize(16);
    long longUnsigned = computeUnsignedSize(LONG_BIT);
    int intUnsigned = computeUnsignedSize(32);

    int charSigned = computeSignedSize(CHAR_BIT);
    // short shortUnsigned = computeUnsignedSize(16);
    printf("%s%d", "calculated unsigned char: ", charSigned);

    putchar('\n');
}

int computeUnsignedSize(int bits) {
    int i, b;
    b = 2;
    for (i = 1; i < bits; ++i) {
        b = 2 * b;
    }
    return b - 1;
}

int computeSignedSize(int bits) {
    int i, b;
    b = 2;
    for (i = 1; i < bits; ++i) {
        b = 2 * b;
    }
    return (b/2 - 1);
}