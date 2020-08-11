#include "util.h"

int isSubsequence(char * s, char * t){
    while (*s != 0 && *t != 0) {
        if (*s == *t) s++;
        t++;
    }
    return *s == 0;
}


int main(int argc, char *argv[]) {
    int ret = isSubsequence(argv[1], argv[2]);
    printf("ret:%d\n", ret);
    return 0;
}
