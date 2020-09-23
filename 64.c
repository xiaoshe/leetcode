#include "util.h"

int minPathSum(int** data, int gridSize, int* gridColSize){
    int m = gridSize;
    if (m == 0) return 0;
    int n = gridColSize[0];
    // m行 n列
    if (n == 0) return 0;

    // 第一行 & 第一列
    for (int i = 1; i < n; i++) data[0][i] += data[0][i-1];
    for (int i = 1; i < m; i++) data[i][0] += data[i-1][0];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int t = data[i-1][j] < data[i][j-1] ? data[i-1][j] : data[i][j-1];
            data[i][j] += t;
        }
    }
    return data[m-1][n-1];
}

int main(int argc, char *argv[]) {
    int a[][32] = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    int m = 3, n = 3;

    /*
    int a[][32] = {
        {0},
        {0}
    };
    int m = 2, n = 1;
    */
    int **grid = array(a, m, n);
    int size[1] = {n};
    int ret = minPathSum(grid, m, size);
    printf("ret:%d\n", ret);
    return 0;
}
