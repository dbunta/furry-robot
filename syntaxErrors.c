#include <stdio.h>

#define MAXLINE 100
#define ESCAPE '\\'

char line[MAXLINE];
int errorLinds[MAXLINE];
int inComment, inDoubleQuote, inSingleQuote;
int curlyCount, bracketCount, parenCount;

int getInput();
void checkSyntax(int len);
void printSyntaxErrors();

int main() {
    int len;
    len = getInput();

    checkSyntax(len);
    printSyntaxErrors();
}

int getInput() {
    int i, c;
    extern char line[];
    for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\\'; ++i) {
        line[i] = c;
    }
    return i + 1;
}

void checkSyntax(int len) {
    int i;
    char c, c2;
    for (i = 0; i < len; ++i) {
        c = line[i];
        c2 = line[i+1];

        if (c == '\n') {
            --inComment;
            continue;
        }

        // if char == / and char + 1 == /
        // in comment = 1
        // if char == /n
        // in comment = 0
        if (c == '/' && c2 == '/') {
            inComment = 1;
        } 

        // if in comment == 0
        // x = single quote, double quote
        // if char is x and inXMode == 0
        // inXMode = 1
        // if char is x and inXMode == 1
        // inXMode = 0
        if (inComment == 0 && inSingleQuote == 0 && inDoubleQuote == 0) {
            
            if (c == '"') {
                inDoubleQuote = 1;
            } else if (c == '\'') {
                inSingleQuote = 1;
            }


            // if in comment == 0 and in double quote == 0 
            // and in single quote == 0
            // x = curly, bracket, paren
            // if char is left x
            // increment x counter
            // if char is right x
            // decrement x counter
            if (c == '{') {
                ++curlyCount;
            } else if (c == '[') {
                ++bracketCount;
            } else if (c == '(') {
                ++parenCount;
            } else if (c == '}') {
                --curlyCount;
            } else if (c == ']') {
                --bracketCount;
            } else if (c == ')') {
                --parenCount;
            }

        } else if (inComment == 0 && inSingleQuote == 0 && inDoubleQuote == 1) {
            if ((c == '"' && c2 == '"') || (c == '\\' && c2 == '"')) {
                //escape double quote
            } else if (c == '"') {
                //exiting double quote
                inDoubleQuote = 0;
            }
        } else if (inComment == 0 && inSingleQuote == 1 && inDoubleQuote == 0) {
            if ((c == '\'' && c2 == '\'') || (c == '\\' && c2 == '\'')) {
                //escaping single quote
            } else if (c == '\'') {
                //exiting single quote
                inSingleQuote = 0;
            }
        }
    }

}

void printSyntaxErrors() {
    if (inDoubleQuote == 1) {
        printf("Missing closing double quote\n");
    } 
    if (inSingleQuote == 1) {
        printf("Missing closing single quote\n");
    }
    if (curlyCount > 0) {
        printf("Missing closing curly brace\n");
    }
    if (bracketCount > 0) {
        printf("Missing closing bracket\n");
    }
    if (parenCount > 0) {
        printf("Missing closing parenthesis\n");
    }
}