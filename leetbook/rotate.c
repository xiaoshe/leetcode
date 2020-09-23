#include "../util.h"


/*
 * 给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

 

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

 */
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int n = matrixSize;
    // 先上下对折
    for (int x = 0; x < n/2; x++) {
        // matrix[x] 与 matrix[n-x-1] 行互换
        for (int y = 0; y < n; y++) {
            int t = matrix[x][y]; matrix[x][y] = matrix[n-x-1][y]; matrix[n-x-1][y] = t;
        }
    }
    // 再对角线对折
    for (int x = 0; x < n; x++) {
        for (int y = x + 1; y < n; y++) {
            // matrix[x][y] matrix[y][x]
            int t = matrix[x][y]; matrix[x][y] = matrix[y][x]; matrix[y][x] = t;
        }
    }
}

int main() {
	int a[][32] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
	};
    int m = 3;
    int n = 3;
    int size[] = {3,4,4};

    int **b = array(a, m, n);
    rotate(b, m, size);
    for (int i = 0; i < m; i++) {
        print_array(b[i], n);
    }
}
