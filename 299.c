#include "util.h"

static char result[64] = {0};
char *getHint(char * secret, char * guess){
    int s[10] = {0};
    int g[10] = {0};
    int a = 0;
    while (*secret != 0) {
        if (*secret == *guess) {
            ++a;
        } else {
            s[*secret - '0']++;
            g[*guess - '0']++;
        }
        ++secret, ++guess;
    }

    int b = 0;
    for (int i = 0; i < 10; i++) {
        int min = g[i] > s[i] ? s[i] : g[i];
        b += min;
    }
    sprintf(result, "%dA%dB", a, b);
    return result;
}

int main(int argc, char *argv[]) {
    char *ret = getHint(argv[1], argv[2]);
    printf("ret:%s\n", ret);
}
