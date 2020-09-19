#include "util.h"

int majorityElement(int* nums, int numsSize){
    int count = 1;
    int n = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == n) count++;
        else {
            count--;
            if (count == 0) n = nums[i+1];
        }
    }
    return n;
}

int main(int argc, char *argv[]) {
    char *file = "data/169.txt";
    FILE *rp = fopen(file, "r");
    char s[128];
    while (fgets(s, 128, rp)) {
        if (s[0] == '#') continue;
        int a[32];
        int n = string_to_array(s, a);
        print_array(a, n);

        // TODO
        int ret = majorityElement(a,n);
        printf("ret:%d\n", ret);    
        
    }
    fclose(rp);
    return 0;
}
