#include "util.hpp"

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int empty = split(text, &words);
        int sz = words.size();
        if (sz == 1) {
            return words[0] + string(empty, ' ');
        } else {
            int avg = empty / (sz - 1);
            string ret(words[0]);
            for (int i = 1; i < sz; i++) {
                ret += string(avg, ' ');
                ret += words[i];
            }
            int left = empty - avg * (sz - 1);
            if (left > 0) {
                ret += string(left, ' ');
            }
            return ret;
        }
    }
    int split(const string& s, vector<string> *word) {
        int cnt = 0;
        string tmp;
        for (size_t i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ' ') {
                cnt++;
                if (!tmp.empty()) {
                    word->push_back(tmp);
                    tmp.clear();
                }
            } else {
                tmp.push_back(ch);
            }
        }
        if (!tmp.empty()) word->push_back(tmp);
        return cnt;
    }
};

void print1(const string& s) {
    printf("|%s|\n", s.c_str());
}
int main(int argc, char *argv[]) {
    string a("  this   is  a sentence ");
    a.assign(" practice   makes   perfect");
    a.assign("hello   world");
    a.assign("  walks  udp package   into  bar a");
    a.assign("a");
    print1(a);
    Solution s;
    string ret = s.reorderSpaces(a);
    print1(ret);
    return 0;
}
