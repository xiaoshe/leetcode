
#include "util.hpp"
#include <algorithm>

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        // 先排序
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<vector<int> > ret;
        for (int i = 0; i < sz - 2; i++) {
            // 第一个数字遍历
            if (nums[i] > 0) break;
            // l指向第2个数字，从前向后扫描
            // r指向第3个数字，从后向前扫描
            int l = i + 1;
            int r = sz - 1;
            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];
                if (s > 0) {
                    r--;
                } else if (s < 0) {
                    l++;
                } else {
                    // 找到后，l和r向内收缩，需要跳过重复数字
                    vector<int> t(3, 0);
                    t[0] = nums[i];
                    t[1] = nums[l];
                    t[2] = nums[r];
                    ret.push_back(t);
                    while (l < r && nums[l+1] == nums[l]) l++;
                    l++;
                    while (l < r && nums[r-1] == nums[r]) r--;
                    r--;
                }
            }
            // 相同则跳过
            while (i < sz - 2 && nums[i+1] == nums[i]) i++;
        }
        return ret;
    }
};


int main(int argc, char *argv[]) {
    vector<int> num;
    StringToVector(argv[1], &num);
    Solution s;
    vector<vector<int> > ret = s.threeSum(num);
    for (size_t i = 0; i < ret.size(); ++i) {
        PrintVector(ret[i]);
    }
    return 0;
}

