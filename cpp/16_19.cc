#include "util.hpp"

void print(const vector< vector<int> >& board) {
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[i].size(); j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

class Solution {
public:
    void go(vector< vector<int> >& data, int x, int y) {
        data[x][y] = -1;
        size++;
        if (x > 0 && data[x-1][y] == 0) go(data, x-1, y); // 上
        if (x < data.size() - 1 && data[x+1][y] == 0) go(data, x+1, y);// 下
        if (y > 0 && data[x][y-1] == 0) go(data, x, y-1); // 左
        if (y < data[x].size() - 1 && data[x][y+1] == 0) go(data, x, y+1); // 右
        if (x > 0 && y > 0 && data[x-1][y-1] == 0) go(data, x-1, y-1); // 左上
        if (x < data.size() - 1 && y > 0 && data[x+1][y-1] == 0) go(data, x+1, y-1); // 左下
        if (x > 0 && y < data[x].size() - 1 && data[x-1][y+1] == 0) go(data, x-1, y+1); // 右上
        if (x < data.size() - 1 && y < data[x].size() - 1 && data[x+1][y+1] == 0) go(data, x+1, y+1); // 右下
    }
    vector<int> pondSizes(vector< vector<int> >& land) {
        vector<int> ret;
        for (size_t i = 0; i < land.size(); i++) {
            for (size_t j = 0; j < land[i].size(); j++) {
                if (land[i][j] == 0) {
                    size = 0;
                    go(land, i, j);
                    ret.push_back(size);
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
private:
    int size;
};

int main(int argc, char *argv[]) {
    int t[32][4] = {
        {0,2,1,0},
        {0,1,0,1},
        {1,1,0,1},
        {0,1,0,1}
    };
    vector< vector<int> > land;
    for (int i = 0; i < 4; i++) {
        //printf("%s\n", t[i]);
        vector<int> c(t[i], t[i]+4);
        land.push_back(c);
    }
    print(land);
    Solution s;
    vector<int> ret = s.pondSizes(land);
    printf("\n");
    print(ret);
    print(land);

    return 0;
}
