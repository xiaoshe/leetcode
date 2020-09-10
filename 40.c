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

#define MAX 501
// 栈
int stack[501]; // 记录位置
int top = -1; // stack大小

// 返回值
int **ret = NULL;
int *sizes = NULL;
int sz = 0;

int sort(int a[], int n, int target) {
    int tmp[201] = {0};
    for (int i = 0; i < n; i++) tmp[a[i]]++;
    int sz = 0;
    for (int i = 0; i < 201; i++) {
        if (i > target) break;
        for (int j = 0; j < tmp[i]; j++) {
            a[sz++] = i;
        }
    }

    return sz;
}

void output() {
    int *t = (int*)malloc(sizeof(int) * (top+1));
    for (int i = 0; i <= top; i++) {
        t[i] = stack[i];
    }
    sizes[sz] = top + 1;
    ret[sz++] = t;
}

void combine(int data[], int n, int start, int target) {
    for (int i = start; i < n; i++) {
        stack[++top] = data[i];
        if (target == data[i]) {
            output();
        } else if (target < data[i]) {
            --top;
            break;
        } else {
            combine(data, n, i+1, target - data[i]);
        }
        while (i+1 < n && data[i] == data[i+1]) i++;
        --top;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    top = -1;
    sz = 0;
    ret = (int**)malloc(sizeof(int*) * MAX);
    sizes = (int*)malloc(sizeof(int) * MAX);

    int n = sort(candidates, candidatesSize, target);

    combine(candidates, n, 0, target);

    *returnSize = sz;
    *returnColumnSizes = sizes;
    return ret;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);

    int sz;
    int *sizes = NULL;
    int **ret = combinationSum2(a, n, atoi(argv[2]), &sz, &sizes);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}
