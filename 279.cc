#include "util.h"
#include "util.hpp"

class Solution {
public:
	int numSquares(int n) {
        printf("n:%d\n", n);
        queue<pair<int, int> > q;
        q.push(make_pair(n, 0));

        vector<bool> visited(n+1, false);

        while (!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 1; n >= i * i; i++) {
                int s = i * i;
                if (num < s) break;
                if (num == s) return step + 1;
                int left = num - s;
                if (visited[left]) continue;
                q.push(make_pair(left, step+1));
                visited[left] = true;

            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int ret = s.numSquares(atoi(argv[1]));
    printf("ret:%d\n", ret);
    return 0;
}
