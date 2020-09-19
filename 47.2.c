#include "util.h"

#define MAX 501
// 栈
int stack[501]; // 记录位置
int top = -1; // stack大小

// 返回值
int **ret = NULL;
int *sizes = NULL;
int sz = 0;

void output() {
    int *t = (int*)malloc(sizeof(int) * (top+1));
    for (int i = 0; i <= top; i++) {
        t[i] = stack[i];
    }
    sizes[sz] = top + 1;
    ret[sz++] = t;
}

void go(int data[], int n, int start) {
    for (int i = start; i < n; i++) {
        stack[++top] = data[i];
        if (top + 1 == n) {
            output();
        } else {
            go(data, n, i+1);
        }
        while (i+1 < n && data[i] == data[i+1]) i++;
        --top;
    }
}

int cmp(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    top = -1;
    sz = 0;
    ret = (int**)malloc(sizeof(int*) * MAX);
    sizes = (int*)malloc(sizeof(int) * MAX);


    qsort(nums, numsSize, sizeof(int), cmp);
    go(nums, numsSize, 0);

    *returnSize = sz;
    *returnColumnSizes = sizes;
    return ret;
}

int main(int argc, char *argv[]) {
    char *file = "data/47.txt";
    FILE *rp = fopen(file, "r");
    char s[128];
    while (fgets(s, 128, rp)) {
        if (s[0] == '#') continue;
        int a[32];
        int n = string_to_array(s, a);
        print_array(a, n);
        printf("start....\n");

        // TODO
        
        int size;
        int *colsize = NULL;
        int **ret = permuteUnique(a, n, &size, &colsize);
        printf("size:%d\n", size);
        for (int i = 0; i < size; i++) {
            print_array(ret[i], n);
        }
        printf("\n");
    }
    fclose(rp);
    return 0;
}
