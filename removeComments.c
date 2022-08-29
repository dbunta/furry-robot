#include <stdio.h>

#define MAXLINE 100

char line[MAXLINE];
int inQuote, inComment;

int getInput();
void removeComments(int len);
void printChar(char currChar, char nextChar);
void reset();

int main() {
    int len = 0;
    len = getInput();
    removeComments(len);
    putchar('\n');
}

int getInput() {
    int i, c;
    extern char line[];
    for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\\'; ++i) {
        line[i] = c;
    }
    return i + 1;
}

void printChar(char currChar, char nextChar) {
    extern int inQuote, inComment;
    if (inQuote == 1 && currChar == '"') {
        inQuote = 0;
    } else if (inQuote == 0 && currChar == '"') {
        inQuote = 1;
    }

    if (inQuote == 0 && inComment == 0 
        && currChar == '/' && nextChar == '/') {
        inComment = 1;
    }

    if (inComment == 0) {
        putchar(currChar);
    }
}

void removeComments(int len) {
    int i;
    extern int inQuote, inComment;
    inComment = inQuote = 0;
    extern char line[];
    for (i = 0; i < len; ++i) {
        if (line[i] == '\n') {
            reset();
        }
        printChar(line[i], line[i+1]);
    }
}

void reset() {
    extern int inQuote, inComment;
    inQuote = inComment = 0;
}

