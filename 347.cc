#include "util.h"
#include "util.hpp"

/*
struct Item {
    int num;
    int cnt;
    Item(int n, int c) : num(n), cnt(c) {}
    bool operator<(const Item& i) const {
        return this->cnt > i.cnt;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 计数
        map<int, int> count;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            map<int, int>::iterator it = count.find(nums[i]);
            if (it == count.end()) {
                count[nums[i]] = 1;
            } else {
                it->second++;
            }
        }

        // topK
        priority_queue<Item, vector<Item> > topk;
        for (map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
            topk.push(Item(it->first, it->second));
            if (topk.size() > k) topk.pop();
        }

        vector<int> ret(k, 0);
        for (int i = 0; i < k; i++) {
            ret[i] = topk.top().num;
            topk.pop();
        }
        return ret;
    }
};
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 计数
        map<int, int> count;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            map<int, int>::iterator it = count.find(nums[i]);
            if (it == count.end()) {
                count[nums[i]] = 1;
            } else {
                it->second++;
            }
        }

        // topK
        priority_queue< pair<int, int> > topk;
        for (map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
            topk.push(pair<int, int>(-it->second, it->first));
            if (topk.size() > k) topk.pop();
        }

        vector<int> ret(k, 0);
        for (int i = 0; i < k; i++) {
            ret[i] = topk.top().second;
            topk.pop();
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    vector<int> t;
    StringToVector(argv[1], &t);
    Solution s;
    vector<int> ret = s.topKFrequent(t, atoi(argv[2]));
    PrintVector(ret);
    return 0;
}
