#include "util.h"

/*
int map(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a';
    } else {
        return ch - 'A' + 26;
    }
}

int longestPalindrome(char * s){
    int count[52] = {0};
    while (*s != 0) {
        count[map(*s)]++;
        s++;
    }
    int sum = 0;
    int odd = 0;
    for (int i = 0; i < 52; i++) {
        if (count[i] % 2 == 1) {
            sum += count[i] - 1;
            odd = 1;
        } else {
            sum += count[i];
        }
    }
    return sum + odd;
}
*/

int longestPalindrome(char * s){
    int count[58] = {0};
    while (*s != 0) {
        count[*s - 'A']++;
        s++;
    }
    int sum = 0;
    int odd = 0;
    for (int i = 0; i < 58; i++) {
        if (count[i] % 2 == 1) {
            sum += count[i] - 1;
            odd = 1;
        } else {
            sum += count[i];
        }
    }
    return sum + odd;
}

int main(int argc, char *argv[]) {
    int ret = longestPalindrome(argv[1]);
    printf("ret:%d\n", ret);
    return 0;
}
