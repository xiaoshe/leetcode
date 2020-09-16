#include "util.h"

int cmp(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

void nextPermutation(int* nums, int numsSize){
    // 从后向前找到一个数字，该数字比后面数字小
    int p = numsSize - 2;
    while (p >= 0 && nums[p] >= nums[p+1]) {
        p--;
    }
    printf("p:%d\n", p);
    if (p < 0) {
        // 未找到
        qsort(nums, numsSize, sizeof(int), cmp);
        return;
    }
    // 后面找到比p大的最小的数，交换位置
    int min = nums[p+1];
    int minp = p+1;
    for (int i = p + 1; i < numsSize; i++) {
        if (nums[i] > nums[p] && nums[i] < min) {
            min = nums[i];
            minp = i;
        }
    }
    printf("p:%d minp:%d\n", p, minp);
    int t = nums[p];
    nums[p] = nums[minp];
    nums[minp] = t;
    
    // 从该数字开始，后面的所有数字由小到大排序，排序范围[p:]
    qsort(nums+p + 1, numsSize-p-1, sizeof(int), cmp);
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    print_array(a, n);

    nextPermutation(a, n);
    print_array(a, n);

    return 0;
}
