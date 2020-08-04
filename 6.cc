#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> tmp(numRows);
        string ret;
        if (s.empty() || numRows < 1) return ret;
        if (numRows == 1) return s;

        bool down = true;
        int cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (down) {
                tmp[cur++].push_back(s[i]);
                if (cur == numRows) {
                    down = false;
                    cur -= 2;
                }
            } else {
                tmp[cur--].push_back(s[i]);
                if (cur < 0) {
                    cur += 2;
                    down = true;
                }
            }
        }
        ret.reserve(s.size());

        for (int i = 0; i < numRows; i++) {
            ret.append(tmp[i]);
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string ret = s.convert(argv[1], atoi(argv[2]));

    printf("ret:%s\n", ret.c_str());
}
