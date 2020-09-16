#include "util.h"

int maxProfit(int* prices, int pricesSize){
    if (pricesSize < 2) return 0;
    int min = prices[0];
    int minp = 0;
    int max = 0;
    for (int i = 1; i < pricesSize; i++) {
        int t = prices[i] - min;
        if (t > max) max = t;
        if (prices[i] < min) min = prices[i];
    }
    return max;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);

    int ret = maxProfit(a, n);
    printf("ret:%d\n", ret);
    return 0;
}
