#include "util.h"

int pos = 0;

int cmp(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int *copy(int *a, int n) {
    int *t = (int*)malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
        t[j] = a[j];
    }
    return t;
}

// 递归调用，将cp拷贝多份，第一个数字与每个不同数字互换构成新的数组递归
// 当s指向最后时，输出数据
void go(int **ret, int *cp, int s, int n) {
    if (s == n) {
        ret[pos++] = cp;
        return;
    }
    int key = cp[s] - 1;
    for (int i = s; i < n; i++) {
        if (cp[i] == key) continue;
        key = cp[i];

        int *t = copy(cp, n);
        // i与第一个交换
        int a = t[i]; t[i] = t[s]; t[s] = a;

        // [s+1, i], 交换后i可能小于前面的数字
        for (int j = i; j > s+1; j--) {
            if (t[j] < t[j-1]) {
                int a = t[j]; t[j] = t[j-1]; t[j-1] = a;
            } else {
                break;
            }
        }

        go(ret, t, s+1, n);
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    pos = 0;
    qsort(nums, numsSize, sizeof(int), cmp);

    int size = 1;
    for (int i = 2; i <= numsSize; i++) size *= i;

    int **ret = (int**)malloc(sizeof(int*) * size);
    int *ret_size = (int *)malloc(sizeof(int) * size);
    for (int k = 0; k < size; k++) {
        ret_size[k] = numsSize;
    }
    go(ret, nums, 0, numsSize);

    *returnSize = pos;
    *returnColumnSizes = ret_size;
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
