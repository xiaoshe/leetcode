#include "util.h"

int uniquePaths(int m, int n){
    int data[101][101];

    // 第一行 & 第一列
    for (int i = 0; i < n; i++) data[0][i] = 1;
    for (int i = 0; i < m; i++) data[i][0] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            data[i][j] = data[i-1][j] + data[i][j-1];
        }
    }

    return data[m-1][n-1];
}

int main(int argc, char *argv[]) {
    int ret = uniquePaths(atoi(argv[1]), atoi(argv[2]));
    printf("ret:%d\n", ret);
    return 0;
}
