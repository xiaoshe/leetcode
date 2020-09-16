#include "util.h"

void print(char **board) {
    printf("board:\n");
    for (int i = 0; i < 9; i++) {
        printf("%s\n", board[i]);
    }
    printf("\n");
}

int check(char** board, int i, int j) {
    int num[10] = {0};
    // 当前行
    for (int k = 0; k < 9; k++) {
        if (board[i][k] == '.') continue;
        int n = board[i][k] - '0';
        if (num[n] > 0) return -1;
        num[n]++;
    }
    // 当前列
    for (int k = 0; k < 10; k++) num[k] = 0;
    for (int k = 0; k < 9; k++) {
        if (board[k][j] == '.') continue;
        int n = board[k][j] - '0';
        if (num[n] > 0) return -2;
        num[n]++;
    }
    // 当前单元格
    for (int k = 0; k < 10; k++) num[k] = 0;
    int row = i / 3 * 3;
    int col = j / 3 * 3;
    for (int r = row; r < row+3; r++) {
        for (int c = col; c < col+3; c++) {
            if (board[r][c] == '.')continue;
            int n = board[r][c] - '0';
            if (num[n] > 0) return -3;
            num[n]++;
        }
    }
    return 1;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    int candidates[9][9][9]= {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int v = board[i][j] - '0' - 1;
                for (int k = 0; k < 9; k++) {
                    candidates[i][k][v] = 1; // 第i行
                    candidates[k][j][v] = 1; // 第j列
                }
                int row = i/3*3;
                int col = j/3*3;
                for (int r = row; r < row+3; r++) {
                    for (int c = col; c < col+3; c++) {
                        candidates[r][c][v] = 1;
                    }
                }
            }
        }
    }
    /*
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d %d\n", i, j);
            for (int k = 0; k < 9; k++) {
                printf("%d ", candidates[i][j][k]);
            }
            printf("\n");
        }
    }
    */

    // 所有空白
    int emptys[81] = {0};
    int empty_size = 0;
    // 记录每个位置的候选数字，如第一个位置候选：124
    int stack[81] = {0};
    int stack_copy[81] = {0};
    int size = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                emptys[empty_size] = i * 10 + j;
                int v = 0;
                for (int k = 0; k < 9; k++) {
                    if (candidates[i][j][k] == 0) {
                        v = v * 10 + k + 1;
                    }
                }
                stack_copy[empty_size] = v;
                stack[empty_size++] = v;
            }
        }
    }
    for (int i = 0; i < empty_size; i++) {
        printf("%d\n", stack[i]);
    }

    while (size < empty_size) {
        // 填数字
        int i = emptys[size] / 10;
        int j = emptys[size] % 10;
        if (stack[size] == 0) {
            // 回溯到上一个位置
            board[i][j] = '.';
            stack[size] = stack_copy[size];
            size--;
            continue;
        }
        board[i][j] = '0' + stack[size] % 10;
        stack[size] /= 10;
        // 判断
        int ret = check(board, i, j);
        if (ret > 0) {
            // 下一个位置
            ++size;
        } else {
            // 失败则当前位置下一个数字
            board[i][j] = '.';
        }
    }
}

int main(int argc, char *argv[]) {
    char *t[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6.....28",
        "...419..5",
        "....8..79"
    };
    char *board[9] = {NULL};
    for (int i = 0; i < 9; i++) {
        char *n = (char*)malloc(10);
        strcpy(n, t[i]);
        board[i] = n;
    }
    print(board);
    int sizes[9] = {9,9,9,9,9,9,9,9,9};
    solveSudoku(board, 9, sizes);

    print(board);
    return 0;
}
