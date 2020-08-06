#include <stdio.h>
#include <limits.h>
#include "util.h"

int isIsomorphic(char * s, char * t){
    char m[256] = {0};
    int cnt[256] = {0};
    while (*s != 0) {
        if (m[*s] == 0) {
            if (cnt[*t] == 0) {
                cnt[*t] = 1;
                m[*s++] = *t++;
            } else {
                return 0;
            }
        } else {
            if (m[*s] != *t) {
                return 0;
            } else {
                s++, t++;
            }
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int ret = isIsomorphic(argv[1], argv[2]);
    printf("%d\n", ret);
}
