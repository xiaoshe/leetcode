#include "util.h"

void dfs(char **grid, int i, int j, int row, int *gridColSize) {
    grid[i][j] = '2';
    if (i > 0 && grid[i-1][j] == '1') dfs(grid, i-1, j, row, gridColSize); // 上
    if (i < row-1 && grid[i+1][j] == '1') dfs(grid, i+1, j, row, gridColSize); // 下
    if (j > 0 && grid[i][j-1] == '1') dfs(grid, i, j-1, row, gridColSize); // 左
    if (j < gridColSize[i]-1 && grid[i][j+1] == '1') dfs(grid, i, j+1, row, gridColSize); // 右
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int row = gridSize;
    if (row == 0) return 0;
    int ret = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                ret++;
                dfs(grid, i, j, row, gridColSize);
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    /*
    char *t[] = {
        "11110",
        "11010",
        "11000",
        "00000"
    };
    */
    char *t[] = {
        "11000",
        "11000",
        "00100",
        "00011"
    };

    int size = 4;
    char **grid = (char **)malloc(sizeof(char *) * size);
    int sizes[32];
    for (int i = 0; i < size; i++) {
        int l = strlen(t[i]);
        printf("l:%d\n", l);
        sizes[i] = l;
        char *a = (char *)malloc(sizeof(char)*(l+1));
        strcpy(a, t[i]);
        a[l] = 0;
        grid[i] = a;
    }
    int ret = numIslands(grid, size, sizes);
    printf("ret:%d\n", ret);
    return 0;
}
