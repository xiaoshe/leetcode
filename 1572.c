#include "util.h"

int diagonalSum(int** mat, int matSize, int* matColSize){
    int n = matSize;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mat[i][i];
        sum += mat[i][n-i-1];
    }
    if (n % 2 == 1) {
        int m = n/2;
        sum -= mat[m][m];
    }
    return sum;
}


int main(int argc, char *argv[]) {
    char *s = " [1,1,1,1], [1,1,1,1], [1,1,1,1], [1,1,1,1]";
    array2d arr = init_array2d(s);
    print_array2d(arr);

    int ret = diagonalSum(arr.data, arr.n, arr.sizes);
    printf("ret:%d\n", ret);
    return 0;
}
