#include <stdio.h>

#define MAXTABSTOP 8

void writeTabsAndSpaces(int charCount, int spaceCount);
void writeSpaces(int spaceCount);
void writeTabs(int tabCount);
void resetCounts();
void incrementCharCount();
int charCount;
int spaceCount;

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            resetCounts();
            putchar(c);
        }
        else if (c == ' ') {
            // count spaces
            ++spaceCount;
            incrementCharCount();
        } else {
            if (spaceCount == 0) {
                putchar(c);
            } else {
                writeTabsAndSpaces(charCount - spaceCount, charCount);
                spaceCount = 0;
                putchar(c);
            }
            incrementCharCount();
        }
    }
}

void writeTabsAndSpaces(int stopCharPos, int continueCharPos) {
    int tabs = (continueCharPos / MAXTABSTOP) - (stopCharPos / MAXTABSTOP);
    int spaces;
    if (continueCharPos < MAXTABSTOP) {
        spaces = continueCharPos - stopCharPos;
    } else {
        spaces = continueCharPos % MAXTABSTOP;
    }
    // int spaces = continueCharPos % MAXTABSTOP;

    if (tabs > 0) writeTabs(tabs);
    if (spaces > 0) writeSpaces(spaces);
}

void writeSpaces(int spaceCount) {
    for (int i = 0; i < spaceCount; ++i) {
        putchar(' ');
    }
}

void writeTabs(int tabCount) {
    for (int i = 0; i < tabCount; ++i) {
        putchar('\t');
    }
}

void resetCounts() {
    charCount = 0;
    spaceCount = 0;
}

void incrementCharCount() {
    ++charCount;
}