// Write the function any(s1, s2) which returns the first location
// in the string s1 where any character from the string s2 occurs, or -1 if s1
// contains no characters from s2. (The standard library function strpbrk does
// the same job but returns a pointer to the location.)

#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    int position;

    char s1[5] = {'f', 'b', 'c', 'd', '\0'};
    char s2[4] = {'a', 'd', 'a', '\0'};

    position = any(s1, s2);
    printf("%d", position);
    return 0;
}

int any(char s1[], char s2[]) {
    int i, j, hasChar;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}