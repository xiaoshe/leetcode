#include "util.h"

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int m = 0;
    int c = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            if (m < c) m = c;
            c = 0;
        } else {
            c++;
        }
    }
    if (m < c) m = c;
    return m;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    int ret = findMaxConsecutiveOnes(a, n);
    printf("ret:%d\n", ret);
    return 0;
}
