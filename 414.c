#include "util.h"

int thirdMax(int* nums, int numsSize){
    int one = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[one]) one = i;
    }
    int two = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == nums[one]) continue;
        if (two == -1) {
            two = i;
            continue;
        }
        if (nums[i] > nums[two]) two = i;
    }
    if (two == -1) return nums[one];
    int three = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= nums[two]) continue;
        if (three == -1) {
            three = i;
            continue;
        }
        if (nums[i] > nums[three]) three = i;
    }
    if (three == -1) return nums[one];
    return nums[three];
}

int main(int argc, char *argv[]) {
    // 数组
    char *s = "1";
    s = "2,2,3,1";
    s = "3,2,1";
    s = "1,2,-2147483648";
    int a[32];
    int n = string_to_array(s, a);
    print_array(a, n);

    int ret = thirdMax(a, n);
    printf("ret:%d\n", ret);

    return 0;
}
