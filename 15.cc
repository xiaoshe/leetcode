#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        // 先排序，再指定3个指针abc
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<vector<int> > ret;
        int a = 0;
        while (a < sz - 2) {
            int b = a + 1;
            while (b < sz - 1) {
                for (int c = b + 1; c < sz; c++) {
                    if (nums[a] + nums[b] + nums[c] == 0) {
                        vector<int> t;
                        t.push_back(nums[a]);
                        t.push_back(nums[b]);
                        t.push_back(nums[c]);
                        ret.push_back(t);
                        break;
                    }
                }
                while (b < sz - 1 && nums[b+1] == nums[b]) b++;
                b++;
            }
            while (a <= sz - 2 && nums[a+1] == nums[a]) a++;
            a++;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    int a[6] = {-1, 0, 1, 2, -1, -4};
    vector<int> t;
    for (int i = 0; i < 6; i++) {
        t.push_back(a[i]);
    }

    Solution s;
    vector<vector<int> > ret = s.threeSum(t);
    for (size_t i = 0; i < ret.size(); ++i) {
        printf("%d %d %d\n", ret[i][0], ret[i][1], ret[i][2]);
    }
}
