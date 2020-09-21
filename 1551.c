#include "util.h"

int y(int x) {
    return x * 2 + 1;
}
int minOperations(int n){
    int mid = n / 2;
    if (n % 2 == 0) {
        int avg = y(mid) - 1;
        int a0 = avg - 1;
        int an = 1;
        return (a0 + an) * mid / 2;
    } else {
        int a0 = y(mid) - 1;
        int an = 0;
        return (a0 + an) * (mid + 1) / 2;
    }
}

int main(int argc, char *argv[]) {
    // 1,3,5,7,9,11 - 5,3,1,1,3,5
    // 1,3,5,7,9    - 4,2,0,2,4
    int ret = minOperations(atoi(argv[1]));
    printf("ret:%d\n", ret);
    return 0;
}
