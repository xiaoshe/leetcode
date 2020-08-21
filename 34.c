#include "util.h"

int search(int nums[], int sz, int key) {
    int low = 0;
    int high = sz - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        printf("%d %d mid:%d key:%d\n", low, high, mid, key);
        if (nums[mid] == key) {
            return mid;
        }
        if (nums[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (low < sz && nums[low] == key) return low;
    return -1;
}

// 二分查找
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    // 先找到
    int find = search(nums, numsSize, target);
    int *ret = (int *)malloc(2 * sizeof(int));
    if (find == -1) {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }

    // 向前折半
    int first = find;
    int l = 0;
    int r = find - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m] == target) {
            first = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (nums[l] == target) first = l;

    // 向后折半
    int second = find;
    l = find + 1;
    r = numsSize - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m] == target) {
            second = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if (nums[r] == target) second = r;
    ret[0] = first;
    ret[1] = second;
    printf("find:%d first:%d second:%d\n", find, first, second);
    return ret;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);

    int sz = 0;
    int *ret = searchRange(a, n, atoi(argv[2]), &sz);
    printf("ret:%d %d\n", ret[0], ret[1]);
    return 0;
}
