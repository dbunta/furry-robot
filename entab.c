#include <stdio.h>

#define MAXTABSTOP 8

void writeTabsAndSpaces(int charCount, int spaceCount);
void writeSpaces(int spaceCount);
void writeTabs(int tabCount);
void resetCounts();
void incrementCharCounts();
int totalCharCount;
int charCount;
int spaceCount;
int tabCount;

//charCountOfInterest = num of chars + num of spaces
// if num of chars + num of spaces > 8
// jjjjjjj j
// if charCount = 8 then use tab
// else use spaces equal to num of spaces
// jjjjjjj  j
//jjj  j
//j  jj
//count chars until no longer counting spaces
// //jjjjjjjjj  j
// jjjjj j
// jj         j
// jj 
// jj j

// spacecount = 9
// charcount = 11
// num of spaces tab will use
// charcount - spacecount = 2
// if ((charcount - spacecount) < spacecount) {
//     //need more spaces
//     // determine of remaining space whether to use tabs or spaces
// } 

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
            incrementCharCounts();
        } else {
            if (spaceCount == 0) {
                // no spaces, so can write char and count
                putchar(c);
            } else {
                // hit character after spaces
                // write tabs and spaces
                //9
                //8
                // printf("%d", charCount);
                //total char count = 19
                //char count = 9
                //space count = 8
                //used chars = 10
                //10 / 8 = 0
                //10 % 8 = 2
                // find where tab is going to take me
                // 19 / 8 = 2
                // 19 % 8 = 3
                // if (#tabs < tabCount) useTab
                writeTabsAndSpaces(charCount, spaceCount);
                resetCounts();
                putchar(c);
            }
            incrementCharCounts();
        }
    }
}


void writeTabsAndSpaces(int charCount, int spaceCount) {
    //if total char count is less than length of tab, no need to tab
    if (charCount <= MAXTABSTOP) {
        writeSpaces(spaceCount);
    } else {
        writeTabs(1);
        ++tabCount;

        int expectedTabCount = totalCharCount / MAXTABSTOP;

        int spacesRemaining = charCount - MAXTABSTOP;
        int tabs = spacesRemaining / MAXTABSTOP;
        int spaces = spacesRemaining % MAXTABSTOP;
        // printf("%d", tabs);
        // printf("%d", spaces);
        // printf("%d", charCount);
        if (tabs > 0) writeTabs(tabs);
        if (spaces > 0) writeSpaces(spaces);
    }
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

void incrementCharCounts() {
    ++charCount;
    ++totalCharCount;
}