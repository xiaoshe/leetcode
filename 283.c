#include "util.h"

void moveZeroes(int* nums, int numsSize){
    int p = 0;
    // 先找到第一个0值，在0后面找到非0与其交换
    while (p < numsSize && nums[p] != 0) p++;
    for (int i = p + 1; i < numsSize; i++) {
        if (nums[i] != 0) {
            int t = nums[i];
            nums[i] = nums[p];
            nums[p] = t;
            p++;
        }
    }
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    moveZeroes(a, n);
    print_array(a, n);
    return 0;
}
