#include <stdio.h>
#include <string.h>

// Write an alternate version of squeeze() that deletes each character
// in s1 that matches any character in the string s2.



void squeeze(char s1[], char s2[]);
void oldSqueeze(char s[], int c);

int main() {
    char s1[5] = {'a', 'b', 'c', 'd', '\0'};
    char s2[4] = {'d', 'b', 'a', '\0'};
    squeeze(s1, s2);
}

void oldSqueeze(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = c;
        }
    }
    s[j] = '\0';
}

void squeeze(char s1[], char s2[]) {
    int i, j, k;

    for (i = 0; s2[i] != '\0'; i++) {
        for (j = k = 0; s1[j] != '\0'; j++) {
            if (s1[j] != s2[i]) {
                // s1[0] = 'c'
                // s1[2] = 'd'
                s1[k++] = s1[j];
            }
        }
        s1[k] = '\0';
    }

    for (i = 0; i < strlen(s1); i++) {
        putchar(s1[i]);
        putchar('\n');
    }
}