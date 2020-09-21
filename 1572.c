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
    /*
    int a[3][32] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    */
    int a[4][32] = {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };
    int sz[32];

    int **b = array(a, 4, 4);
    int ret = diagonalSum(b, 4, sz);
    printf("ret:%d\n", ret);
    return 0;
}
