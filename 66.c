#include <stdio.h>
#include <limits.h>
#include "util.h"

int* plusOne(int* digits, int digitsSize, int* returnSize){
    *returnSize = digitsSize+1;
    int *ret = (int*)malloc(*returnSize*sizeof(int));
    int tail = digitsSize;
    int flag = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        int n = flag + digits[i];
        if (n > 9) {
            flag = 1;
            n -= 10;
        } else {
            flag = 0;
        }
        ret[tail--] = n;
    }
    ret[tail] = flag;
    if (ret[0] == 0) {
        for (int i = 1; i < *returnSize; i++) {
            ret[i-1] = ret[i];
        }
        *returnSize -= 1;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_vector(argv[1], a);
    int sz = 0;
    int* ret = plusOne(a, n, &sz);
    print_array(ret, sz);
}
