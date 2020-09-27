#include "util.hpp"

string ComputeKey(const string& str) {
    int ch[26] = {0};
    for (size_t i = 0; i < str.size(); i++) {
        ch[str[i] - 'a'] += 1;
    }
    string ret;
    for (int i = 0; i < 26; i++) {
        if (ch[i] > 0) {
            char s[8];
            sprintf(s, "%d", ch[i]);
            ret.append(s);
            ret.append(1, i + 'a');
        }
    }
    return ret;
}

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > data;
        for (size_t i = 0; i < strs.size(); i++) {
            string k = ComputeKey(strs[i]);
            map<string, vector<string> >::iterator it = data.find(k);
            if (it == data.end()) {
                vector<string> t;
                t.push_back(strs[i]);
                data[k] = t;
            } else {
                it->second.push_back(strs[i]);
            }
        }
        vector<vector<string> > ret;
        ret.reserve(data.size());
        for (map<string, vector<string> >::iterator it = data.begin(); it != data.end(); it++) {
            ret.push_back(it->second);
        }
        return ret;
    }
};

int main() {
    vector<string> strs;
    SplitString("eat tea tan ate nat bat", ' ', &strs);
    Solution s;
    vector<vector<string> > ret = s.groupAnagrams(strs);
    for (size_t i = 0; i < ret.size(); i++) {
        print(ret[i]);
    }

    return 0;
}
