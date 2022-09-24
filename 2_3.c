#include <stdio.h>
#include <string.h>

int main() {
    char h[] = "15fa";
    int i, dec, t, len;
    dec = 0;
    len = strlen(h);
    for (i = 0; i < len; ++i) {
        if (h[i] == '0' && (h[i+1] == 'x' || h[i+1]=='X')) {
            i += 2;
        } else {
            if (h[i] >= '0' && h[i] <= '9') {
                t = h[i] - '0';
            } else if (h[i] >= 'A' && h[i] <= 'F') {
                t = h[i] - 'A' + 10;
                // t = h[i] - 55;
            } else if (h[i] >= 'a' && h[i] <= 'f') {
                t = h[i] - 'a' + 10;
                // t = h[i] - 87;
            }
        }
        dec = dec * 16 + t;
    }
    printf("%d", dec);
}