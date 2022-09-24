#include <stdio.h>

int main() {
    
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        
    }
    //write withoutusing && and ||
    //i must be less than lim - 1
    //c must not equal \n or EOF
    for (i = 0; (i < lim - 1) * ((c=getchar()) != '\n') * (c != EOF) == 1; ++i) {
    }
    return 0;
}