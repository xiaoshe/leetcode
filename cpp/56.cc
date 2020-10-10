#include "util.hpp"

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}
class Solution {
public:
    vector< vector<int> > merge(vector< vector<int> >& intervals) {
        vector< vector<int> > ret;
        if (intervals.empty()) return ret;
        sort(intervals.begin(), intervals.end(), cmp);

        vector<int> t(intervals[0]);
        for (size_t i = 1; i < intervals.size(); i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if (s > t[1]) {
                ret.push_back(t);
                t[0] = s; t[1] = e;
            } else {
                if (e > t[1]) t[1] = e;
            }
        }
        ret.push_back(t);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    int a[][32] = {{1,3},{2,6},{8,10},{15,18}};
    vector< vector<int> > input;
    for (int i = 0; i < 4; i++) {
        vector<int> b(a[i], a[i]+2);
        input.push_back(b);
    }
    print(input);

    Solution s;
    vector< vector<int> > ret = s.merge(input);
    print(ret);
    return 0;
}
