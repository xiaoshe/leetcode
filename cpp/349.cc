#include "util.hpp"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> uniq;
        for (size_t i = 0; i < nums1.size(); i++) {
            uniq[nums1[i]] = 1;
        }

        vector<int> ret;
        for (size_t i = 0; i < nums2.size(); i++) {
            map<int, int>::iterator it = uniq.find(nums2[i]);
            if (it != uniq.end()) {
                uniq.erase(it);
                ret.push_back(nums2[i]);
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    char *s1 = "1,2,2,1";
    char *s2 = "2,2";
    vector<int> a = StringToVector(s1);
    vector<int> b = StringToVector(s2);
    Solution s;
    vector<int> ret = s.intersection(a, b);
    print(ret);
    return 0;
}
