#include "util.h"

int combine_size(int n, int k) {
    if (k > n / 2) k = n - k;
    int s = 1;
    for (int i = 1; i <= k; i++) {
        s *= n--;
        s /= i;
    }
    return s;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int sz = combine_size(n, k);
    printf("%d\n", sz);
    *returnSize = sz;

    // 申请空间
    int **ret = (int**)malloc(sizeof(int*) * sz);
    int *sizes = (int*)malloc(sizeof(int) * sz);
    for (int i = 0; i < sz; i++) {
        // 多申请一个int空间，用于临界值判断
        int *t = (int*)malloc(sizeof(int) * (k+1));
        t[k] = n + 1;
        ret[i] = t;
        sizes[i] = k;
    }
    *returnColumnSizes = sizes;

    //
    for (int i = 0; i < k; i++) {
        ret[0][i] = i + 1;
    }
    int p = 1;
    while (p < sz) {
        // ret[p] = ret[p-1] + 1
        int *pre = ret[p-1];
        int *cur = ret[p];

        // n=6 k=3, 1,2,3,6 -> 1,2,4,6
        int pos = k - 1;
        while (pos >= 0) {
            if (pre[pos] < pre[pos+1] - 1) {
                break;
            }
            pos--;
        }
        for (int i = 0; i < pos; i++) {
            cur[i] = pre[i];
        }
        cur[pos] = pre[pos] + 1;
        for (int i = pos + 1; i < k; i++) {
            cur[i] = cur[i-1] + 1;
        }
        p++;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **ret = combine(n, k, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        int *a = ret[i];
        int sz = returnColumnSizes[i];
        print_array(a, sz);
    }

    return 0;
}
