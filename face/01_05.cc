#include "../util.hpp"

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first.size() == second.size()) {
            return update(first, second);
        } else if (first.size() == second.size() + 1) {
            return insert(second, first);
        } else if (first.size() == second.size() - 1) {
            return insert(first, second);
        } else {
            return false;
        }
    }

    bool update(const string& first, const string& second) {
        int error = 0;
        for (size_t i = 0; i < first.size(); i++) {
            if (first[i] != second[i]) {
                error++;
                if (error > 1) return false;
            }
        }
        return true;
    }

    // first.size < second.size
    bool insert(const string& first, const string& second) {
        int error = 0;
        for (size_t i = 0; i < first.size(); i++) {
            if (first[i] != second[i+error]) {
                error++;
                i--;
                if (error > 1) return false;
            }
        }
        return true;
    }
};
int main(int argc, char *argv[]) {
    string s1("pale");
    string s2("ple");
    s1 = "teacher";
    s2 = "bleacher";
    Solution s;
    bool ret = s.oneEditAway(s1, s2);
    printf("ret:%d\n", ret);
    return 0;
}
