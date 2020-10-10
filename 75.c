#include "util.h"

void sortColors(int* nums, int numsSize){
    int red = 0, white = 0, blue = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) red++;
        else if (nums[i] == 1) white++;
        else blue++;
    }
    int i = 0;
    while (red-- > 0) nums[i++] = 0;
    while (white-- > 0) nums[i++] = 1;
    while (blue-- > 0) nums[i++] = 2;
}

int main(int argc, char *argv[]) {
    char *s = "2,0,2,1,1,0";
    int a[32];
    int n = string_to_array(s, a);
    print_array(a, n);

    sortColors(a, n);
    print_array(a, n);

    return 0;
}
