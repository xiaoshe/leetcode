#include "../util.hpp"

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        return (s1+s1).find(s2) != string::npos;
    }
};
int main(int argc, char *argv[]) {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    Solution s;
    int ret = s.isFlipedString(s1, s2);
    printf("ret:%d\n", ret);
    return 0;
}
