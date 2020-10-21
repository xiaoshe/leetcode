#include "util.h"

// 动态规划，f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-1)*f(0)
int numTrees(int n){
    if (n <= 2) return n;
    int *f = (int*)malloc(sizeof(int) * (n+1));

    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; i++) {
        int s = 0;
        for (int j = 0; j < i; j++) {
            s += f[j] * f[i-j-1];
        }
        f[i] = s;
    }
    int ret = f[n];
    free(f);
    return ret;
}

int main(int argc, char *argv[]) {

    int ret = numTrees(atoi(argv[1]));
    printf("ret:%d\n", ret);
    return 0;
}
