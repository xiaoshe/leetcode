#include "util.h"

// 超出时间限制
int go(int* nums, int low, int high, int target) {
    if (low > high) return 0;
    int m = (low + high)/2;
    if (nums[m] == target || nums[low] == target || nums[high] == target) return 1;
    return go(nums, m+1, high, target) || go(nums, low, m-1, target);
}
int search(int* nums, int numsSize, int target){
    return go(nums, 0, numsSize-1, target);
}
/*
// [-9,-8,-8,-8,-8,-7,-7,-7,-7,-7,-7,-6,-6,-6,-6,-6,-5,-5,-4,-4,-4,-4,-4,-4,-4,-3,-3,-3,-3,-3,-2,-1,-1,-1,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,8,8,8,9,9,9,9,10,10,10,10,-10,-10,-10,-10,-10,-10,-9,-9,-9] 13
int search(int* nums, int numsSize, int target){
    return 0;
}
*/

int main(int argc, char *argv[]) {
    // 数组
    char *s = "2,5,6,0,0,1,2";
    int a[32];
    int k = 0;
    int n = string_to_array(s, a);
    print_array(a, n);

    int ret = search(a, n, k);
    printf("ret:%d\n", ret);


    return 0;
}
