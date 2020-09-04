#include "util.h"


char *multiply(char *num1, char *num2){
    if (*num1 == '0' || *num2 == '0') {
        char *ret = (char*)malloc(2);
        ret[0] = '0';
        ret[1] = 0;
        return ret;
    }
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int l = l1 + l2;

    // 初始化
    int *ret = (int *)malloc(l * sizeof(int));
    for (int i = 0; i < l; i++) ret[i] = 0;

    // 相乘
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            int n1 = num1[l1 - i - 1] - '0';
            int n2 = num2[l2 - j - 1] - '0';
            int tail = l - (i + j) - 1;
            ret[tail] += n1 * n2;
        }
    }
    // 进位
    int tail = l - 1;
    while (tail > 0) {
        int n = ret[tail];
        ret[tail] = n % 10;
        ret[tail - 1] = ret[tail - 1] + n / 10;
        tail--;
    }
    while (ret[tail] == 0) tail++;
    // 返回
    int len = l - tail + 1;
    char *out = (char *) malloc(len);
    char *p = out;
    for (int i = tail; i < l; i++) {
        *p++ = ret[i] + '0';
    }
    *p = 0;
    free(ret);
    return out;
}


int main(int argc, char *argv[]) {
    char *ret = multiply(argv[1], argv[2]);
    printf("ret:%s\n", ret);
    return 0;
}
