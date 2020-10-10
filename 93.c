#include "util.h"

void go(char *s, int index, int len) {
}

char ** restoreIpAddresses(char * s, int* returnSize){
    int slen = strlen(s);
    go(s, 0, slen);
}

int main(int argc, char *argv[]) {
    // 数组
    char *s = "";

    int sz = 0;
    char **ret = restoreIpAddresses(s, &sz);
    print_string(ret, sz);

    return 0;
}
