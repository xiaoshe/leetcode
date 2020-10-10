#include "util.hpp"

class Solution {
public:
    int maxProductPath(vector< vector<int> >& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // 第一行
        for (int j = 1; j < col; j++) {
            grid[0][j] *= grid[0][j-1];
        }
        for (int i = 1; i < row; i++) {
            grid[i][0] *= grid[i-1][0];
        }

        for (int x = 1; x < row; x++) {
            for (int y = 1; y < col; y++) {
                int top = grid[x-1][y] * grid[x][y];
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int ret = s.maxProductPath(grid);
    printf("ret:%d\n", ret);
    return 0;
}
