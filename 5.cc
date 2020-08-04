#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        int max = 0;
        int begin = 0;
        for (int i = 0; i < sz; i++) {
            int left = i;
            int j = i;
            // 如果字母相同，则向右移动
            while (i < sz && s[j] == s[left]) j++;
            int right = j - 1;
            // left向左，right向右
            while (right < sz && left >= 0 && s[right] == s[left]) {
                left--, right++;
            }
            left++, right--;
            if (right - left + 1 > max) {
                max = right - left + 1;
                begin = left;
            }
        }
        return s.substr(begin, max);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;

    string s = sol.longestPalindrome(argv[1]);
    printf("%s\n", s.c_str());

    return 0;
}
