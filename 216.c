#include "util.h"

void print(int data[], int a[], int n) {
    printf("stack:");
    for (int i = 0; i < n; i++) {
        printf("[%d]%d ", a[i], data[a[i]]);
    }
    printf("\n");
}

void print2(int data[], int n) {
    printf("stack:");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

#define MAX 12
int stack[10];
int top = -1;

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

void combine(int start, int target, int k) {
    for (int i = start; i < 10; i++) {
        stack[++top] = i;
        if (target == i && top+1 == k) {
            output();
        } else if (target < i) {
            --top;
            break;
        } else {
            combine(i+1, target - i, k);
        }
        --top;
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    top = -1;
    sz = 0;
    ret = (int**)malloc(sizeof(int*) * MAX);
    sizes = (int*)malloc(sizeof(int) * MAX);

    combine(1, n, k);

    *returnSize = sz;
    *returnColumnSizes = sizes;
    return ret;
}

int main(int argc, char *argv[]) {
    int target = atoi(argv[1]);
    int k = atoi(argv[2]);

    int sz;
    int *sizes = NULL;
    int **ret = combinationSum3(k, target, &sz, &sizes);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    for (int n = 6; n <= 45; n++) {
        for (int k = 1; k <= 9; k++) {
            int sz;
            int *sizes = NULL;
            int **ret = combinationSum3(k, n, &sz, &sizes);
            printf("sum:%d k:%d size:%d\n", n, k, sz);
            for (int i = 0; i < sz; i++) {
                free(ret[i]);
            }
            free(sizes);
            free(ret);
        }
    }

    return 0;
}
