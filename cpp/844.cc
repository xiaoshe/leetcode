#include "util.hpp"

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int sback = 0, tback = 0;
        int i = S.size() - 1, j = T.size() - 1;
        while (i >= 0 && j >= 0) {
            i = next(S, i, &sback);
            j = next(T, j, &tback);
            if (i < 0 || j < 0) break;
            if (S[i] != T[j]) return false;
            i--, j--;
        }
        printf("%d %d\n", i, j);
        if (i < 0) {
            return next(T, j, &tback) < 0;
        } else {
            return next(S, i, &sback) < 0;
        }
    }
    // 从后向前找到一个有效字符
    int next(const string& s, int index, int *count) {
        while (index >= 0) {
            if (s[index] == '#') {
                *count += 1;
            } else {
                if (*count == 0) return index;
                else *count -= 1;
            }
            index--;
        }
        return index;
    }
};

int main(int argc, char *argv[]) {

    Solution s;
    bool ret = s.backspaceCompare(argv[1], argv[2]);
    printf("%d\n", ret);
    return 0;
}
