
#include "util.hpp"
#include <algorithm>

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        // 先排序
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<vector<int> > ret;
        for (int i = 0; i < sz - 3; i++) {
            // 第一个数字
            for (int j = i + 1; j < sz - 2; j++) {
                // 第2个数字
                // l指向第3个数字，从前向后扫描
                // r指向第4个数字，从后向前扫描
                int l = j + 1;
                int r = sz - 1;
                while (l < r) {
                    int s = nums[i] + nums[j] + nums[l] + nums[r];
                    if (s > target) {
                        r--;
                    } else if (s < target) {
                        l++;
                    } else {
                        // 找到后，l和r向内收缩，需要跳过重复数字
                        vector<int> t(4, 0);
                        t[0] = nums[i];
                        t[1] = nums[j];
                        t[2] = nums[l];
                        t[3] = nums[r];
                        ret.push_back(t);
                        while (l < r && nums[l+1] == nums[l]) l++;
                        l++;
                        while (l < r && nums[r-1] == nums[r]) r--;
                        r--;
                    }
                }
                while (j < sz - 2 && nums[j+1] == nums[j]) j++;
            }
            while (i < sz - 3 && nums[i+1] == nums[i]) i++;
        }
        return ret;
    }
};


int main(int argc, char *argv[]) {
    vector<int> num;
    StringToVector(argv[1], &num);
    Solution s;
    vector<vector<int> > ret = s.fourSum(num, StringToInt(argv[2]));
    printf("result size:%ld\n", ret.size());
    for (size_t i = 0; i < ret.size(); ++i) {
        print(ret[i]);
    }
    return 0;
}

