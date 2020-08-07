#include "util.h"

char *convertToBase7(int num){
    if (num == 0) {
        char *ret = (char *)malloc(2);
        strcpy(ret, "0");
        return ret;
    }
    char tmp[32] = {0};
    char *p = tmp + 30;
    int neg = 0;
    if (num < 0) {
        neg = 1;
        num = 0 - num;
    }
    while (num > 0) {
        int m = num % 7;
        printf("m:%d\n", m);
        num /= 7;
        *p-- = m + '0';
    }
    if (neg == 1) {
        *p-- = '-';
    }
    char *ret = (char *)malloc(tmp + 32 - p);
    strcpy(ret, p+1);
    return ret;
}

int main(int argc, char *argv[]) {
    printf("%d\n", -1/2);
    char *ret = convertToBase7(atoi(argv[1]));
    printf("ret:%s\n", ret);
    return 0;
}
