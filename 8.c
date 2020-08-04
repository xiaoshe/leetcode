#include <stdio.h>
#include <limits.h>

int myAtoi(char *str) {
    long ret = 0;
    int neg = 0;
    char *p = str;
    while (*p == ' ') p++;
    if (*p != '+' && *p != '-' && (*p < '0' || *p > '9')) {
        return 0;
    }
    if (*p == '+' || *p == '-') {
        if (*p == '-') neg = 1;
        p++;
    }
    while (*p >= '0' && *p <= '9') {
        ret = ret * 10 + *p - '0';
        if (ret > INT_MAX) break;
        p++;
    }
    if (neg == 0) {
        return ret > INT_MAX ? INT_MAX : ret;
    } else {
        ret = 0 - ret;
        return ret < INT_MIN ? INT_MIN : ret;
    }
}

int main(int argc, char *argv[]) {
    int ret = myAtoi(argv[1]);
    printf("ret:%d\n", ret);
}
