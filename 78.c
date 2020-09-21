#include "util.h"


int stack[1000];
int top = 0;
int **ret = NULL;
int size = 0;
int *sizes = NULL;

void output() {
    int *t = (int*)malloc(sizeof(int) * top);
    for (int i = 0; i < top; i++) {
        t[i] = stack[i];
    }
    sizes[size] = top;
    ret[size++] = t;
}

// 从num中选择max个数，从p开始
void go(int* nums, int numsSize, int p, int max) {
    stack[top++] = nums[p];
    if (top == max) {
        output();
    } else {
        for (int i = p + 1; i < numsSize; i++) {
            go(nums, numsSize, i, max);
        }
    }
    --top;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    ret = (int**)malloc(sizeof(int*) * 5000);
    sizes = (int*)malloc(sizeof(int) * 5000);
    size = 0;
    top = 0;

    ret[0] = (int*)malloc(sizeof(int)*1);
    sizes[size++] = 0;
    for (int k = 1; k <= numsSize; k++) {
        for (int i = 0; i < numsSize - k + 1; i++) {
            go(nums, numsSize, i, k);
        }
    }
    *returnSize = size;
    *returnColumnSizes = sizes;
    return ret;
}

int main(int argc, char *argv[]) {
    char *file = "data/78.txt";
    FILE *rp = fopen(file, "r");
    char s[128];
    while (fgets(s, 128, rp)) {
        if (s[0] == '#') continue;
        int a[32];
        int n = string_to_array(s, a);
        print_array(a, n);

        // TODO
        
        int sz;
        int *sizes = NULL;
        int **ret = subsets(a, n, &sz, &sizes);
        for (int i = 0; i < sz; i++) {
            print_array(ret[i], sizes[i]);
        }
        
    }
    fclose(rp);
    return 0;
}
