#include "util.h"

// 动态规划：dp[n] = dp[n-1] + dp[n-2]
int climbStairs(int n) {
    int p1 = 1, p2 = 1, cur = 1;
    for (int i = 2; i <= n; i++) {
        cur = p1 + p2;
        p2 = p1;
        p1 = cur;
    }
    return cur;
}

int main(int argc, char *argv[]) {
    int ret = climbStairs(atoi(argv[1]));
    printf("ret:%d\n", ret);
    return 0;
}
