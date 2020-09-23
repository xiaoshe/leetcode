#include "../util.hpp"

class Solution {
public:
    string compressString(string s) {
        string ret;
        if (s.empty()) return ret;
        char pre = s[0] - 1;
        int n = 0;
        for (size_t i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (pre != ch) {
                push(&ret, n, pre);
                pre = ch;
                n = 1;
            } else {
                n++;
            }
        }
        push(&ret, n, pre);
        return ret.size() < s.size() ? ret : s;
    }
    void push(string *ret, int n, char ch) {
        if (n == 0) return;
        char t[32];
        sprintf(t, "%c%d", ch, n);
        ret->append(t);
    }
};
int main(int argc, char *argv[]) {
    string s1 = "aabcccccaaa";
    Solution s;
    string s2 = s.compressString(s1);
    printf("ret:%s\n", s2.c_str());
    return 0;
}
