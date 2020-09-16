#include "util.h"

// dp[i] = min(dp[i-1] + cost[i], dp[i-2] + cost[i])
int minCostClimbingStairs(int* cost, int costSize){
    if (costSize <= 1) return 0;
    if (costSize == 2) return cost[0] > cost[1] ? cost[1] : cost[0];

    int dp0 = cost[0];
    int dp1 = cost[1];
    for (int i = 2; i < costSize; i++) {
        int m1 = dp0 + cost[i];
        int m2 = dp1 + cost[i];
        int dp2 = m1 > m2 ? m2 : m1;
        dp0 = dp1;
        dp1 = dp2;
    }
    return dp1 < dp0 ? dp1 : dp0;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    print_array(a, n);

    int ret = minCostClimbingStairs(a, n);
    printf("ret:%d\n", ret);
    return 0;
}
