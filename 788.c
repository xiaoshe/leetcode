#include "util.h"

int data[10001] = {0};
int size = 1;


int isDigit(int n) {
    int copy = n;
    int k = 0;
    int base = 1;
    while (n > 0) {
        int m = n % 10;
        if (m == 0 || m == 1 || m == 8) {
            ;
        } else if (m == 2) {
            m = 5;
        } else if (m == 5) {
            m = 2;
        } else if (m == 6) {
            m = 9;
        } else if (m == 9) {
            m = 6;
        } else {
            return 0;
        }
        k = k + base * m;
        base *= 10;
        n /= 10;
    }
    return k != copy;
}

int rotatedDigits(int N){
    if (N >= size) {
        for (int i = size; i <= N; i++) {
            data[i] = data[i-1] + isDigit(i);
        }
    }
    return data[N];
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int ret = rotatedDigits(n);
    for (int i = 1; i <= n; i++) {
        printf("[%d] %d \n", i, data[i]);
    }

    printf("%d\n", ret);
    return 0;
}
