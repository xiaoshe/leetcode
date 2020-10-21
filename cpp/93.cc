#include "util.hpp"

class Solution {
public:
    vector<string> data;
    vector<string> ret;
    vector<string> restoreIpAddresses(string s) {
        go(s, 0, s.size());
        return ret;
    }
    void go(const string& s, int index, int slen) {
        int sz = data.size();
        if (sz > 4) return;
        if (sz == 4 && index == slen) {
            // 输出，注意不能清空data，所以不用stack
            string t(data[0]);
            for (size_t i = 1; i < data.size(); i++) {
                t = t + "." + data[i];
            }
            ret.push_back(t);
            return;
        }
        if (index == slen) return;
        if (s[index] == '0') {
            data.push_back(s.substr(index, 1));
            go(s, index+1, slen);
            data.pop_back();
            return;
        }
        int left = slen - index;
        if (left >= 1) {
            data.push_back(s.substr(index, 1));
            go(s, index+1, slen);
            data.pop_back();
        }
        if (left >= 2) {
            data.push_back(s.substr(index, 2));
            go(s, index+2, slen);
            data.pop_back();
        }
        if (left >= 3) {
            string t(s.substr(index, 3));
            if (valid(t)) {
                data.push_back(t);
                go(s, index+3, slen);
                data.pop_back();
            }
        }
    }
    bool valid(const string& s) const {
        int t = s[0] - '0';
        t = t * 10 + s[1] - '0';
        t = t * 10 + s[2] - '0';
        return t < 256;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<string> ret = s.restoreIpAddresses(argv[1]);
    print(ret);
    return 0;
}
