#include <stdio.h>

#define N 10
#define MAXLINE 100

void fold();
void getLine();
void printFold(int start, int end);
int getFoldPos(int start), getLineCount();

char line[MAXLINE];
int len;

int main() {
    char input[MAXLINE];

    getLine();
    fold();
}

void getLine() {
    // populates array with input chars
    int i, c;
    extern char line[];
    extern int len;
    for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    len = i;
}

int getLineCount() {
    extern int len;
    int lineCount = len / N;
    if (len % N > 0) {
        lineCount += 1;
    }
    return lineCount;
}

void fold() {
    int i, lineCount, spacePos, lastPos;
    lastPos = 0;
    lineCount = getLineCount();
    for (i = 0; i < lineCount; ++i) {
        //position of space
        spacePos = getFoldPos(lastPos);
        printFold(lastPos, spacePos);
        lastPos = spacePos + 1;
    }
}

int getFoldPos(int start) {
    int i, spacePos;
    spacePos = 0;
    for (i = start; i < (start + N); ++i) {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
            spacePos = i;
        }
    }
    if (spacePos == 0) {
        return i;
    }
    return spacePos;
}

void printFold(int start, int end) {
    int i;
    for (i = start; i < end; ++i) {
        putchar(line[i]);
    }
    putchar('\n');
}