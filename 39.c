#include "util.h"

void print(int data[], int a[], int n) {
    printf("stack:");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[a[i]]);
    }
    printf("\n");
}

#define MAX 501
int stack[501]; // 记录位置
int top = -1; // stack大小
int sum = 0; // 记录stack中数值和

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **ret = (int**)malloc(sizeof(int*) * MAX);
    int *sizes = (int*)malloc(sizeof(int) * MAX);
    int sz = 0;

    int p = candidatesSize - 1;
    while (p >= 0) {
        sum += candidates[p];
        stack[++top] = p;

        if (sum >= target) {
            if (sum == target) {
                // 输出
                sizes[sz] = top + 1;
                int *t = (int*)malloc(sizeof(int) * (top+1));
                for (int i = 0; i <= top; i++) {
                    t[i] = candidates[stack[i]];
                }
                ret[sz] = t;
                sz++;
            }
            // 连续pop出顶部数字，push一个更小的数
            while (top >= 0) {
                p = stack[top--];
                sum -= candidates[p];
                if (p > 0) break;
            }
            p--;
        }
    }
    *returnSize = sz;
    *returnColumnSizes = sizes;

    return ret;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);

    int sz;
    int *sizes = NULL;
    int **ret = combinationSum(a, n, atoi(argv[2]), &sz, &sizes);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}
