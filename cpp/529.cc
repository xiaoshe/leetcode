#include "util.hpp"

void print(const vector< vector<char> >& board) {
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[i].size(); j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

class Solution {
public:
    void go(vector< vector<char> >& data, int x, int y) {
        // 判断周围几颗雷
        int n = 0;
        if (x > 0 && data[x-1][y] == 'M') n++; // 上
        if (x < data.size() - 1 && data[x+1][y] == 'M') n++;// 下
        if (y > 0 && data[x][y-1] == 'M') n++; // 左
        if (y < data[x].size() - 1 && data[x][y+1] == 'M') n++; // 右
        if (x > 0 && y > 0 && data[x-1][y-1] == 'M') n++; // 左上
        if (x < data.size() - 1 && y > 0 && data[x+1][y-1] == 'M') n++; // 左下
        if (x > 0 && y < data[x].size() - 1 && data[x-1][y+1] == 'M') n++; // 右上
        if (x < data.size() - 1 && y < data[x].size() - 1 && data[x+1][y+1] == 'M') n++; // 右下
        if (n == 0) {
            data[x][y] = 'B';
            if (x > 0 && data[x-1][y] == 'E') go(data, x-1, y); // 上
            if (x < data.size() - 1 && data[x+1][y] == 'E') go(data, x+1, y);// 下
            if (y > 0 && data[x][y-1] == 'E') go(data, x, y-1); // 左
            if (y < data[x].size() - 1 && data[x][y+1] == 'E') go(data, x, y+1); // 右
            if (x > 0 && y > 0 && data[x-1][y-1] == 'E') go(data, x-1, y-1); // 左上
            if (x < data.size() - 1 && y > 0 && data[x+1][y-1] == 'E') go(data, x+1, y-1); // 左下
            if (x > 0 && y < data[x].size() - 1 && data[x-1][y+1] == 'E') go(data, x-1, y+1); // 右上
            if (x < data.size() - 1 && y < data[x].size() - 1 && data[x+1][y+1] == 'E') go(data, x+1, y+1); // 右下
        } else {
            data[x][y] = '0' + n;
        }
    }
    vector< vector<char> > updateBoard(vector< vector<char> >& board, vector<int>& click) {
        vector< vector<char> > ret(board);
        int x = click[0], y = click[1];
        if (ret[x][y] == 'M') {
            ret[x][y] = 'X';
        } else {
            go(ret, x, y);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    /*
    const char *t[32] = {
        "EEEEE",
        "EEMEE",
        "EEEEE",
        "EEEEE"
    };
    vector<int> click(2, 0);
    click[0] = 3;
    click[1] = 0;
    */
    /*
    const char *t[32] = {
        "B1E1B",
        "B1M1B",
        "B111B",
        "BBBBB"
    };
    vector<int> click(2, 0);
    click[0] = 1;
    click[1] = 2;
    */
    const char *t[32] = {
        "EEEEEEEE",
        "EEEEEEEM",
        "EEMEEEEE",
        "MEEEEEEE",
        "EEEEEEEE",
        "EEEEEEEE",
        "EEEEEEEE",
        "EEMMEEEE"
    };
    vector<int> click(2, 0);
    click[0] = 0;
    click[1] = 0;

    vector< vector<char> > board;
    for (int i = 0; i < 32; i++) {
        if (t[i] == NULL) break;
        //printf("%s\n", t[i]);
        string a(t[i]);
        vector<char> c(a.begin(), a.end());
        board.push_back(c);
    }
    print(board);
    Solution s;
    vector< vector<char> > ret = s.updateBoard(board, click);
    printf("\n");
    print(ret);

    return 0;
}
