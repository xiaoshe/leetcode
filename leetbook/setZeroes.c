#include "../util.h"


/*
 * 编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
  示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

 */
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int m = matrixSize;
    if (m == 0) return;
    int n = matrixColSize[0];

    int *zero_rows = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) zero_rows[i] = 0;
    int *zero_cols = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) zero_cols[i] = 0;

    // 含0的行和列
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                zero_rows[i] = 1;
                zero_cols[j] = 1;
            }
        }
    }

    // 清零
    for (int i = 0; i < m; i++) {
        if (zero_rows[i] == 1) {
            for (int j = 0; j < n; j++) matrix[i][j] = 0;
        }
    }

    for (int j = 0; j < n; j++) {
        if (zero_cols[j] == 1) {
            for (int i = 0; i < m; i++) matrix[i][j] = 0;
        }
    }
    free(zero_rows);
    free(zero_cols);
}

int main() {
    /*
	int a[][32] = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
	};
    int m = 3;
    int n = 3;
    int size[] = {3,3,3};
    */
	int a[][32] = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
	};
    int m = 3;
    int n = 4;
    int size[] = {4,4,4};

    int **b = array(a, m, n);
    setZeroes(b, m, size);
    for (int i = 0; i < m; i++) {
        print_array(b[i], n);
    }
}
