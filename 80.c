#include "util.h"

int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    int k = nums[0];
    int c = 1;
    int top = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == k) {
            c++;
            if (c <= 2) {
                nums[top++] = nums[i];
            }
        } else {
            k = nums[i];
            c = 1;
            nums[top++] = nums[i];
        }
    }
    return top;
}

int main(int argc, char *argv[]) {
    char *s = "1,1,1,2,2,3";
    s = "1,1,1,2,2,2,3,4,4,4";
    int a[32];
    int n = string_to_array(s, a);

    int sz = removeDuplicates(a, n);
    print_array(a, sz);

    return 0;
}
