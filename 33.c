#include "util.h"

int search(int* nums, int numsSize, int target){
    int low = 0, high = numsSize - 1;
    while (low <= high) {
        printf("%d %d\n", low, high);
        int mid = (low + high) / 2;
        if (target == nums[mid]) {
            return mid;
        }
        if (nums[low] <= nums[mid]) {
            // 左侧有序
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            // 右侧有序
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    // 数组
    char *s = "4,5,6,7,0,1,2";
    int k = 0;
    /*
    s = "3,1";
    k = 1;
    */
    int a[32];
    int n = string_to_array(s, a);
    print_array(a, n);
    int ret = search(a, n, k);
    printf("ret:%d\n", ret);

    return 0;
}
