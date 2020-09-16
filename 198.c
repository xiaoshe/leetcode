#include "util.h"

/*
int r(int *nums, int start, int sz) {
    printf("start:%d %d\n", start, sz);
    if (start == sz) return 0;
    if (start + 1 == sz) return nums[start];
    if (start + 2 == sz) return nums[start] > nums[start+1] ? nums[start] : nums[start+1];

    int t1 = nums[start] + r(nums, start + 2, sz);
    int t2 = r(nums, start+1, sz);
    return t1 > t2 ? t1 : t2;
}

int rob(int* nums, int numsSize){
    return r(nums, 0, numsSize);
}
*/

int rob(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int dp[101] = {0};
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < numsSize; i++) {
        int t1 = dp[i-1];
        int t2 = dp[i-2] + nums[i];
        dp[i] = t1 > t2 ? t1 : t2;
    }
    return dp[numsSize - 1];
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    int ret = rob(a, n);
    printf("ret:%d\n", ret);
    return 0;
}
