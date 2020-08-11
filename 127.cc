#include "util.hpp"

class Solution {
public:
    int diff(const string& a, const string& b) const {
        int c = 0;
        int sz = a.size();
        for (int i = 0; i < sz; ++i) {
            if (a[i] != b[i]) c++;
        }
        return c;
    }
    int find(const string& end, const vector<int>& pos, const vector<string>& wordList) const {
        for (size_t i = 0; i < pos.size(); ++i) {
            if (wordList[pos[i]] == end) return 1;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 将begin下一个放入数据pos
        int sz = wordList.size();
        vector<int> pos; 
        pos.reserve(sz);
        vector<int> used(sz, 0);
        for (int i = 0; i < sz; i++) {
            if (diff(beginWord, wordList[i]) == 1) {
                pos.push_back(i);
                used[i] = 1;
            }
        }

        int ret = 1;
        for (size_t i = 0; i < pos.size(); i++) {
            if (wordList[pos[i]] == endWord) {
                return ret + 1;
            }

            vector<int> tmp;
            for (int i = 0; i < sz; i++) {
                if (used[i] == 0 && diff(beginWord, wordList[i]) == 1) {
                    tmp.push_back(i);
                    used[i] = 1;
                }
            }
            ret += 1;
            pos = tmp;
        }
    }
};

int main() {
    string begin("hit");
    string end("cog");
    vector<string> l;
    l.push_back("hot");
    l.push_back("dot");
    l.push_back("dog");
    l.push_back("lot");
    l.push_back("cog");

    Solution s;
    int ret = s.ladderLength(begin, end, l);
}
