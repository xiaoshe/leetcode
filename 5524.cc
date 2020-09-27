#include "util.hpp"

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        vector<int> cost;

        int total = 0;
        for (size_t i = 0; i < customers.size(); i++) {
            total += customers[i];
            if (total > 4) {
                cost.push_back(4 * boardingCost - runningCost);
                total -= 4;
            } else {
                cost.push_back(total * boardingCost - runningCost);
                total = 0;
            }
        }
        while (total > 0) {
            if (total > 4) {
                cost.push_back(4 * boardingCost - runningCost);
                total -= 4;
            } else {
                cost.push_back(total * boardingCost - runningCost);
                total = 0;
            }
        }
        print(cost);
    }
};

int main(int argc, char *argv[]) {
    int a[32] = {8,3};
    vector<int> customers(a, a+2);
    int boardingCost = 5;
    int runningCost = 6;

    Solution s;
    s.minOperationsMaxProfit(customers, boardingCost, runningCost);

    return 0;
}
