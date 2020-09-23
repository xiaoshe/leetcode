#include "../util.h"

int canPermutePalindrome(char* s){
    int p[128] = {0};
    while (*s != 0) {
        p[*s]++;
        s++;
    }
    int k = 0;
    for (int i = 0; i < 128; i++) {
        if (p[i] % 2 == 1) k++;
    }
    return k <= 1;
}

int main(int argc, char *argv[]) {
    char *s = "tactcoa";
    int ret = canPermutePalindrome(s);
    printf("ret:%d\n", ret);
    return 0;
}
