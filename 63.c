#include "util.h"

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int data[101][101];
    int m = obstacleGridSize;
    if (m == 0) return 0;
    int n = obstacleGridColSize[0];
    // m行 n列
    if (n == 0) return 0;
    if (obstacleGrid[0][0] == 0) data[0][0] = 1;
    else return 0;

    // 第一行 & 第一列
    for (int i = 1; i < n; i++) {
        if (obstacleGrid[0][i] == 0) data[0][i] = data[0][i-1];
        else data[0][i] = 0;
    }
    for (int i = 1; i < m; i++) {
        if (obstacleGrid[i][0] == 0) data[i][0] = data[i-1][0];
        else data[i][0] = 0;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                data[i][j] = data[i-1][j] + data[i][j-1];
            } else {
                data[i][j] = 0;
            }
        }
    }
    return data[m-1][n-1];
}

int main(int argc, char *argv[]) {
    char *s = "[0,0,0],[0,1,0],[0,0,0]";
    array2d arr = init_array2d(s);
    print_array2d(arr);

    int ret = uniquePathsWithObstacles(arr.data, arr.n, arr.sizes);
    printf("ret:%d\n", ret);
    return 0;
}
