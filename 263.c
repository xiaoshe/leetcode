#include "util.h"

int isUgly(int num) {
    if (num < 0) return 0;
    while (num > 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else if (num % 3 == 0) {
            num /= 3;
        } else if (num % 5 == 0) {
            num /= 5;
        } else {
            return 0;
        }
    }
    return 1;
}

int test() {
    int m = 0x7fffffff;
    printf("max:%d\n", m);


    int max = m;
    int n = 0;
    while (max > 2) {
        max /= 2;
        n++;
    }
    n++;
    printf("2 : %d\n", n);
    int ret = 1;
    while (n-- > 0) {
        ret *= 2;
    }
    printf("ret:%d\n", ret);

    max = m;
    n = 0;
    while (max > 3) {
        max /= 3;
        n++;
    }
    n++;
    printf("3 : %d\n", n);

    max = m;
    n = 0;
    while (max > 5) {
        max /= 5;
        n++;
    }
    n++;
    printf("5 : %d\n", n);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int ret = isUgly(atoi(argv[1]));
    printf("n:%d ret:%d\n", n, ret);

    test();
    return 0;
}
