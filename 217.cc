#include "util.hpp"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
	    set<int> val;
        for (size_t i = 0; i < nums.size(); ++i) {
            set<int>::iterator it = val.find(nums[i]);
            if (it != val.end()) {
                return true;
            } else {
                val.insert(nums[i]);
            }
        }    
        return false;
    }
};

int main(int argc, char *argv[]) {
    vector<int> val;
    StringToVector(argv[1], &val);
    print(val);
    Solution s;
    bool ret = s.containsDuplicate(val);
    printf("ret:%d\n", ret);
}
