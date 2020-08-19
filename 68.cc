#include "util.hpp"

class Solution {
public:
    void MakeString(const vector<string>& words, int width, bool last, string *ret) {
        ret->reserve(width);
        int sz = words.size();
        if (sz == 1) {
            ret->assign(words[0]);
            ret->append(width - words[0].size(), ' ');
            return;
        }
        if (last) {
            ret->assign(words[0]);
            for (int i = 1; i < sz; ++i) {
                ret->append(1, ' ');
                ret->append(words[i]);
            }
            ret->append(width - ret->size(), ' ');
            return;
        }
        int total = 0;
        for (int i = 0; i < sz; ++i) {
            total += words[i].size();
        }
        // 将空格均匀插入
        int space_number = width - total;
        int avg = space_number / (sz - 1);
        int mod = space_number % (sz - 1);
        ret->assign(words[0]);
        for (int i = 1; i < sz; ++i) {
            ret->append(avg, ' ');
            if (mod > 0) {
                ret->append(1, ' ');
                mod--;
            }
            ret->append(words[i]);
        }
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int tmp_sum = 0;
        vector< vector<string> > cache;
        vector<string> tmp;
        for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
            int l = (*it).size();
            if (tmp_sum == 0) {
                tmp.push_back(*it);
                tmp_sum += l;
            } else {
                if (tmp_sum + l + 1 > maxWidth) {
                    // 满
                    cache.push_back(tmp);
                    tmp.clear();
                    tmp_sum = 0;
                    tmp.push_back(*it);
                    tmp_sum += l;
                } else {
                    tmp.push_back(*it);
                    tmp_sum += l + 1;
                }
            }
        }
        if (!tmp.empty()) {
            cache.push_back(tmp);
        }

        vector<string> ret;
        for (size_t i = 0; i < cache.size(); i++) {
            string str;
            MakeString(cache[i], maxWidth, i == cache.size() - 1, &str);
            ret.push_back(str);
        }
        return ret; 
    }
};

int main(int argc, char *argv[]) {
    //const char *w[7] = {"This", "is", "an", "example", "of", "text", "justification."};
    const char *w[6] = {"What","must","be","acknowledgment","shall","be"};
    vector<string> words;
    for (int i = 0; i < 6; i++) {
        words.push_back(w[i]);
    }
    Solution s;
    vector<string> ret = s.fullJustify(words, 16);
    PrintVector(ret);
    return 0;
}
