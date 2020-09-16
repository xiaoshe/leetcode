#include "util.h"

/*
int cmp(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int canMakeArithmeticProgression(int* arr, int arrSize){
    if (arrSize < 3)return 1;
    qsort(arr, arrSize, sizeof(int), cmp);
    int d = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++) {
        int t = arr[i] - arr[i-1];
        if (t != d) return 0;
    }
    return 1;
}
*/


// 方法二：利用公式 s = (a0 + an) *n/2
int canMakeArithmeticProgression(int* arr, int arrSize){
    int max = -10000000;
    int min = 10000000;
    int sum = 0;
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    int t = (min + max) * arrSize;
    return t % 2 == 0 && t / 2 == sum;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    int ret = canMakeArithmeticProgression(a, n);
    printf("%d\n", ret);
    return 0;
}
