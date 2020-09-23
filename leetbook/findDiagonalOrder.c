#include "../util.h"


/*
 * 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
 *
 *  
 *
 *  示例:
 *
 *  输入:
 *  [
 *   [ 1, 2, 3 ],
 *   [ 4, 5, 6 ],
 *   [ 7, 8, 9 ]
 *  ]
 *  输出:  [1,2,4,7,5,3,6,8,9]
 */

int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int m = matrixSize;
    if (m == 0) {
        *returnSize = 0;
        return NULL;
    }
    int n = matrixColSize[0];
    int total = m * n;
    *returnSize = total;
    int *ret = (int *)malloc(total * sizeof(int));

    // 处理
    char direction = 'u'; // u:向上，d:向下
    int x = 0, y = 0;
    for (int i = 0; i < total; i++) {
        ret[i] = matrix[x][y];
        if (direction == 'u') {
            x--, y++;
            if (x < 0) {
                direction = 'd';
                if (y < n) {
                    x = 0;
                } else {
                    x += 2;
                    y -= 1;
                }
            } else if (y == n) {
                direction = 'd';
                x += 2;
                y -= 1;
            }
        } else {
            x++, y--;
            if (y < 0) {
                direction = 'u';
                if (x < m) {
                    y = 0;
                } else {
                    x -= 1;
                    y += 2;
                }
            } else if (x == m) {
                direction = 'u';
                x -= 1;
                y += 2;
            }
        }
    }
    return ret;
}

int main() {
	int a[][32] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
	};
    int m = 3;
    int n = 3;
    int size[] = {3,3,3};

    int **b = array(a, m, n);
    int sz = 0;
    int *ret = findDiagonalOrder(b, m, size, &sz);
    print_array(ret, sz);
}
