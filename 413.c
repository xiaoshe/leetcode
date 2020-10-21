#include "util.h"

// 等差数列：1,2,3,4,5 可以划分成6(1+2+3)个子等差数列(必须连续)：长度为5的有1个，长度为4的有2个，长度为3的有3个
// 故等差数列长度为n，则有1+2+3+...+(n-2)个子等差数列,即(n-1)*(n-2)/2
int numberOfArithmeticSlices(int* A, int ASize){
    if (ASize < 3) return 0;
    int begin = 0;
    int d = A[1] - A[0];
    int i = 2;
    int ret = 0;
    while (i < ASize) {
        if (A[i] - A[i-1] == d) {
            // 等差
            i++;
        } else {
            // 不等差
            int n = i - begin;
            ret += (n - 1) * (n - 2) / 2;
            begin = i - 1;
            d = A[i] - A[i-1];
            i++;
        }
    }
    int n = i - begin;
    ret += (n - 1) * (n - 2) / 2;
    return ret;
}

int main(int argc, char *argv[]) {
    // 数组
    char *s = "1,2,3,4,5,7,9,11";
    int a[32];
    int n = string_to_array(s, a);
    print_array(a, n);

    int ret = numberOfArithmeticSlices(a, n);
    printf("ret:%d\n", ret);

    return 0;
}
