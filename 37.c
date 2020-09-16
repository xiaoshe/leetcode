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
    // 所有空白
    int emptys[81] = {0};
    int empty_size = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                emptys[empty_size++] = i * 10 + j;
            }
        }
    }

    // 记录填入字符
    int stack[81] = {0};
    int size = 0;
    while (size < empty_size) {
        // 填数字
        int i = emptys[size] / 10;
        int j = emptys[size] % 10;
        stack[size] += 1;
        if (stack[size] > 9) {
            // 回溯到上一个位置
            board[i][j] = '.';
            stack[size--] = 0;
            continue;
        }
        board[i][j] = '0' + stack[size];
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
