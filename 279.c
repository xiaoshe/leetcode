#include "util.h"

int numSquares(int n){
    int c = 0;
    while (n > 0) {
        int k = (int)sqrt(n);
        printf("k:%d\n", k);
        n -= k * k;
        c++;
    }
    return c;
}

int main(int argc, char *argv[]) {
    int ret = numSquares(atoi(argv[1]));
    printf("ret:%d\n", ret);
    return 0;
}
