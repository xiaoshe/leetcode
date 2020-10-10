#include "util.h"


int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int m = matrixSize;
    if (m == 0) {
        *returnSize = 0;
        return NULL;
    }

    int n = matrixColSize[0];
    int total = m * n;
    int *ret = (int *)malloc(sizeof(int) * total);
    *returnSize = total;

    // 旋转
    int x = 0, y = 0;
    // 记录边框，方向改变时缩小边框
    int top = 1, bottom = m, left = 0, right = n;
    int direction = 1;
    for (int i = 0; i < total; i++) {
        ret[i] = matrix[x][y];
        if (direction == 1) { // 右
            y++;
            if (y == right) {
                x++;
                y--;
                right--;
                direction = 2;
            }
        } else if (direction == 2) { // 下
            x++;
            if (x == bottom) {
                x--;
                y--;
                bottom--;
                direction = 3;
            }
        } else if (direction == 3) { // 左
            y--;
            if (y < left) {
                y = left++;
                x--;
                direction = 4;
            }
        } else { // 上
            x--;
            if (x < top) {
                x = top++;
                y++;
                direction = 1;
            }
        }
    }
    return ret;
}

int main() {
    /*
    int m = 3;
    int n = 4;
    int size[32] = {};
    size[0] = n;
    int m = 5, n = 5;
    int size[32] = {};
    size[0] = n;
    */

    char *s = "[1,2,3], [4,5,6], [7,8,9]";
    s = "[1,2,3,4],[5,6,7,8],[9,10,11,12]";
	s = "[1,2,3,4,5], [6,7,8,9,10], [11,12,13,14,15], [16,17,18,19,20], [21,22,23,24,25]";
    array2d arr = init_array2d(s);
    print_array2d(arr);
    int sz = 0;
    int *ret = spiralOrder(arr.data, arr.n, arr.sizes, &sz);
    print_array(ret, sz);

    return 0;
}
