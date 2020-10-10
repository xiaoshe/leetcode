#include <stdlib.h>
#include "util.hpp"

class Solution {
public:
    vector< vector<string> > solveNQueens(int n) {
        vector<int> t(n, 0);
        vector< vector<int> > flag(n, t);

        vector<int> stack(n, -1); // 一行只能放一个，记录放置的列位置
        vector< vector<string> > ret;
        int row = 0;
        while (row >= 0) {
            int next = stack[row] + 1;
            int p = -1;
            for (int j = next; j < n; j++) {
                if (flag[row][j] == 0) {
                    p = j;
                    break;
                }
            }
            if (p == -1) {
                if (row == n) break;
                // 本行未找到合适位置，回溯
                stack[row] = -1;
                row--;
                if (row >= 0) {
                    set(flag, row, stack[row], -1);
                }
                continue;
            } else {
                // 找到合适位置，放置
                set(flag, row, p, 1);
                stack[row] = p;
                row++;
                if (row == n) {
                    // 输出
                    vector<string> t;
                    out(stack, &t);
                    ret.push_back(t);
                    // next
                    row--;
                    set(flag, row, stack[row], -1);
                }
            }
        }
        return ret;
    }
private:
    void set(vector< vector<int> >& flag, int i, int j, int m) const {
        int n = flag.size();
        flag[i][j] += m;
        // 向下
        for (int k = i+1; k < n; k++) {
            flag[k][j] += m;
        }
        // 右下
        int k = 1;
        while (i + k < n && j + k < n) {
            flag[i+k][j+k] += m;
            k++;
        }
        // 左下
        k = 1;
        while (j - k >= 0 && i + k < n) {
            flag[i+k][j-k] += m;
            k++;
        }
    }

    void out(const vector<int>& stack, vector<string> *ret) {
        int n = stack.size();
        for (int i = 0; i < n; i++) {
            string t(n, '.');
            t[stack[i]] = 'Q';
            ret->push_back(t);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector< vector<string> > ret = s.solveNQueens(atoi(argv[1]));
    for (size_t i = 0; i < ret.size(); i++) {
        printf("[%ld]:\n", i);
        for (size_t j = 0; j < ret[i].size(); j++) {
            printf("  %s\n", ret[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}
