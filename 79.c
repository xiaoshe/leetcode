#include "util.h"


int path[200][200] = {0};
int check(char** board, int boardSize, int* boardColSize, int i, int j, char * word){
    word++;
    if (*word == 0) return 1;
    path[i][j] = 1;
    // 上下左右
    if (i>0 && path[i-1][j] == 0 && board[i-1][j] == *word) {
        if (check(board, boardSize, boardColSize, i-1, j, word) == 1) return 1;
    }
    if (i<boardSize-1 && path[i+1][j] == 0 && board[i+1][j] == *word) {
        if (check(board, boardSize, boardColSize, i+1, j, word) == 1) return 1;
    }
    if (j>0 && path[i][j-1] == 0 && board[i][j-1] == *word) {
        if (check(board, boardSize, boardColSize, i, j-1, word) == 1) return 1;
    }
    if (j<boardColSize[i]-1 && path[i][j+1] == 0 && board[i][j+1] == *word) {
        if (check(board, boardSize, boardColSize, i, j+1, word) == 1) return 1;
    }
    path[i][j] = 0;
    return 0;    
}

int exist(char** board, int boardSize, int* boardColSize, char * word){
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            path[i][j] = 0;
        }
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == *word && check(board, boardSize, boardColSize, i, j, word)) {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //char board[5][5] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    char *board[3] = {"ABCE", "SFCS", "ADEE"};
    int boardSize = 3;
    int boardColSize[3] = {4,4,4};
    char *word = "ABCCED";
    word = "ABCB";
    word = "SEE";

    int ret = exist(board, boardSize, boardColSize, word);
    printf("ret:%d\n", ret);
    return 0;
}
