#include "util.h"

int pos = 0;

int *copy(int *a, int n) {
    int *t = (int*)malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
        t[j] = a[j];
    }
    return t;
}

// 递归调用，将cp拷贝多份，当s指向n时输出数据
void go(int **ret, int *cp, int s, int n) {
    if (s == n) ret[pos++] = cp;
    for (int i = s; i < n; i++) {
        int *t = copy(cp, n);
        // i与s交换
        int a = t[i];
        t[i] = t[s];
        t[s] = a;
        go(ret, t, s+1, n);
    }
}

// 全排列：先计算数量，
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    pos = 0;
    int size = 1;
    for (int i = 2; i <= numsSize; i++) {
        size *= i;
    }

    int **ret = (int**)malloc(sizeof(int*) * size);
    int *ret_size = (int *)malloc(sizeof(int) * size);
    for (int k = 0; k < size; k++) {
        ret_size[k] = numsSize;
    }
    go(ret, nums, 0, numsSize);

    *returnSize = size;
    *returnColumnSizes = ret_size;
    return ret;
}


int main(int argc, char *argv[]) {
    char *file = "data/46.txt";
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
        int **ret = permute(a, n, &size, &colsize);
        printf("size:%d\n", size);
        for (int i = 0; i < size; i++) {
            print_array(ret[i], n);
        }
        printf("\n");
    }
    fclose(rp);
    return 0;
}
