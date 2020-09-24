#include "util.h"

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    // init
    int **ret = (int**)malloc(sizeof(int*)*n);
    int *sizes = (int*)malloc(sizeof(int) *n);
    for (int i = 0; i < n; i++) {
        int *t = (int*)malloc(sizeof(int)*n);
        ret[i] = t;
        sizes[i] = n;
    }
    *returnSize = n;
    *returnColumnSizes = sizes;

    // deal
    int total = n * n;
    // 旋转
    int x = 0, y = 0;
    // 记录边框，方向改变时缩小边框
    int top = 1, bottom = n, left = 0, right = n;
    int direction = 1;
    for (int i = 0; i < total; i++) {
        ret[x][y] = i+1;
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

int main(int argc, char *argv[]) {
    int n = 5;
    int size = 0;
    int *sizes = NULL;
    int **ret = generateMatrix(n, &size, &sizes);
    for (int i = 0; i < size; i++) {
        print_array(ret[i], size);
    }

    return 0;
}
