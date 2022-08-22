#include <stdio.h>

#define MAXTABSTOP 8

void writeTab(int currCharCount);
void resetCurrCharCount(int currCharCount);


int main() {
    int currCharCount = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            writeTab(currCharCount);
            currCharCount = 0;
        } else if (c == '\n') {
            currCharCount = 0;
            putchar(c);
        } else {
            ++currCharCount;
            putchar(c);
        }
    }
}

void writeTab(int currCharCount) {
    int tabSpaces = MAXTABSTOP - currCharCount;
    if (tabSpaces < 1) {
        tabSpaces = MAXTABSTOP - (currCharCount % MAXTABSTOP);
    } 
    for (int i = 0; i < tabSpaces; ++i) {
        putchar(' ');
    }
}