#include "util.h"

int searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrixSize == 0 || matrixColSize[0] == 0 || target < matrix[0][0]) return 0;
    int m = matrixSize, n = matrixColSize[0];
    if (target > matrix[m-1][n-1]) return 0;

    // 先查列
    int s = 0, e = m - 1;
    while (s < e) {
        int m = (s + e) / 2 + 1;
        printf("%d %d %d\n", s, e, m);
        if (matrix[m][0] == target) return 1;
        else if (matrix[m][0] > target) {
            e = m - 1;
        } else {
            s = m;
        }
    }
    printf("s:%d\n", s);
    int p = s;
    s = 0;
    e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (matrix[p][m] == target) return 1;
        else if (matrix[p][m] > target) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char *s = "[1,   3,  5,  7], [10, 11, 16, 20], [23, 30, 34, 50]";
    //s = "[1],[3]";
    int target = 13;

    array2d arr = init_array2d(s);
    print_array2d(arr);
    int ret = searchMatrix(arr.data, arr.n, arr.sizes, target);
    printf("ret:%d\n", ret);

    return 0;
}
