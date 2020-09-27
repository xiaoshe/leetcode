#include "util.hpp"

class Solution {
public:
    int maximumRequests(int n, vector< vector<int> >& requests) {
        vector<int> t(n, 0);
        vector< vector<int> > data(n, t);
        vector< vector<int> > copy(data);

        for (size_t i = 0; i < requests.size(); i++) {
            int from = requests[i][0];
            int to = requests[i][1];
            data[from][to]++;
        }

        int ret = 0;
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data[0].size(); j++) {
                if (i == j) {
                    ret += data[i][j];
                    data[i][j] = 0;
                }
                if (data[i][j] == 0) continue;
                int n = circle(data, i, j);
                if (n > 0) {
                    ret += n;
                    j--;
                }
            }
        }
        return ret;
    }
    int circle(vector< vector<int> >& data, int x, int y) {
        vector<int> from(21, 0);

        queue<int> q;
        q.push(y);
        from[y] = x;

        bool find = false;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int nxt = q.front();
                q.pop();
                if (nxt == x) {
                    find = true;
                    break;
                }
                for (size_t j = 0; j < data.size(); j++) {
                    if (data[nxt][j] > 0) {
                        q.push(j);
                        from[j] = nxt;
                    }
                }
            }
        }
        if (!find) return 0;
        print(from);
    }
};

int main(int argc, char *argv[]) {
    int n = 5;
    vector< vector<int> > data;
    vector<int> t;

    Solution s;
    int ret = s.maximumRequests(n, data);
    return 0;
}
