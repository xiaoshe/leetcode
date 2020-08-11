#include "util.h"

static char buf[5101];

int add(char buf[], int p, int n) {
    int flag = 0;
    if (n >= 10) {
        flag = 1;
        n -= 10;
    }
    buf[p] = n + '0';
    return flag;
}

char * addStrings(char * num1, char * num2){
    int l1 = strlen(num1) - 1;
    int l2 = strlen(num2) - 1;
    int p = 5100;
    int flag = 0; // 进位
    while (l1 >= 0 && l2 >= 0) {
        int n = num1[l1--] - '0' + num2[l2--] - '0' + flag;
        flag = add(buf, p--, n);
    }
    while (l1 >= 0) {
        int n = num1[l1--] - '0' + flag;
        flag = add(buf, p--, n);
    }
    while (l2 >= 0) {
        int n = num2[l2--] - '0' + flag;
        flag = add(buf, p--, n);
    }
    if (flag == 1) {
        add(buf, p, 1);
    } else {
        p++;
    }
    char *ret = (char *)malloc(5101 - p + 1);
    char *t = ret;
    for (int i = p; i < 5101; i++) {
        *t++ = buf[i];
    }
    *t = 0;
    return ret;
}

int main(int argc, char *argv[]) {
    char *ret = addStrings(argv[1], argv[2]);
    printf("ret:%s\n", ret);

    return 0;
}
