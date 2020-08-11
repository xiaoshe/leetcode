#include "util.h"


int firstUniqChar(char * s){
    char m[128] = {0};
    char *p = s;
    while (*p != 0) {
        if (m[*p] < 2) {
            m[*p]++;
        }
        p++;
    }
    p = s;
    while (*p != 0) {
        if (m[*p] == 1) {
            return p - s;
        }
        p++;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    int ret = firstUniqChar(argv[1]);
    printf("ret:%d\n", ret);
    return 0;
}
