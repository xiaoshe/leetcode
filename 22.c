#include "util.h"

char **ret = NULL;
int size = 0;

void go(int left, int right, char *cp, int sz, int p) {
    if (left > right) return;
    if (left == 0 && right == 0) {
        char *t = (char *)malloc(sizeof(char)*sz);
        strcpy(t, cp);
        ret[size++] = t;
        return;
    }
    if (left > 0) {
        cp[p] = '(';
        go(left-1, right, cp, sz, p+1);
        cp[p] = 0;
    }
    if (right > 0) {
        cp[p] = ')';
        go(left, right-1, cp, sz, p+1);
        cp[p] = 0;
    }
}

char **generateParenthesis(int n, int* returnSize){
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    ret = (char **)malloc(sizeof(char*) * 10000);
    size = 0;

    char *t = (char *)malloc(sizeof(char)* (2*n+1));
    memset(t, 0, 2*n+1);
    go(n, n, t, 2*n+1, 0);

    *returnSize = size;
    free(t);
    return ret;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int sz;
    char **ret = generateParenthesis(n, &sz);
    print_string(ret, sz);

    return 0;
}
