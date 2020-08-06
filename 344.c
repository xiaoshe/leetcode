#include "util.h"

void reverseString(char* s, int sSize){
    int i = 0, j = sSize - 1;
    while (i < j) {
        char ch = s[i];
        s[i] = s[j];
        s[j] = ch;
        i++, j--;
    }
}

int main(int argc, char *argv[]) {
    char p[32];
    strcpy(p, argv[1]);
    reverseString(p, strlen(p));
    printf("%s\n", p);
    return 0;
}
