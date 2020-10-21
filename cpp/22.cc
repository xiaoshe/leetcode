
#include "util.hpp"
#include <algorithm>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        go(ret, n, n, "");
        return ret;
    }
    void go(vector<string>& ret, int left, int right, const string& s) {
        if (left > right) return;
        if (left == 0 && right == 0) {
            ret.push_back(s);
            return;
        }
        if (left > 0) go(ret, left-1, right, s + "(");
        if (right > 0) go(ret, left, right-1, s + ")");
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    int n = atoi(argv[1]);
    vector<string> ret = s.generateParenthesis(n);
    print(ret);
    return 0;
}

