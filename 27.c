#include <stdio.h>
#include <limits.h>
#include "util.h"

int removeElement(int* nums, int numsSize, int val){
    if (numsSize == 0) return 0;
    int head = 0;
    int tail = numsSize - 1;
    while (head < tail) {
        if (nums[head] != val) {
            head++;
        } else {
            // 找到val
            while (tail > head && nums[tail] == val) tail--;
            if (tail > head) {
                int t = nums[head];
                nums[head] = nums[tail];
                nums[tail] = t;
                head++;
                tail--;
            } else {
                return head;
            }
        }
    }
    return (nums[head] == val) ? head : head + 1;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_vector(argv[1], a);

    int ret = removeElement(a, n, atoi(argv[2]));
    printf("ret:%d\n", ret);
    print_vector(a, n);
}
