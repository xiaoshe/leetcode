#include "util.h"


// 
int coinChange(int* coins, int coinsSize, int amount){
    // dp[i]: 代表金额i的最少硬币
    int *dp = (int*)malloc(sizeof(int) * (amount+1));
    for (int i = 0; i < amount+1; i++) dp[i] = -1;
    dp[0] = 0;
    for (int k = 1; k <= amount; k++) {
        int min = -1;
        for (int i = 0; i < coinsSize; i++) {
            int pre = k - coins[i];
            if (pre >= 0 && dp[pre] != -1) {
                if (min < 0) min = dp[pre];
                else if (min > dp[pre]) min = dp[pre];
            }
        }
        if (min == -1) dp[k] = -1;
        else dp[k] = min + 1;
    }
    int ret = dp[amount];
    free(dp);
    return ret;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    int ret = coinChange(a, n, atoi(argv[2]));
    printf("ret:%d\n", ret);
    return 0;
}
