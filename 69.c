#include "util.h"

int mySqrt(int x) {
    if (x < 2) return x;
    int max = 0;
    int s = 0, e = x;
    while (s <= e) {
        int mid = (s + e) / 2;
        printf("%d %d %d\n", s, e, mid);
        if (mid == 0) return 0;
        int r = x / mid;
        if (r == mid) return mid;
        else if (r < mid) e = mid-1;
        else {
            s = mid+1;
            max = mid;
        }
    }
    return max;
}

int main(int argc, char *argv[]) {
    int ret = mySqrt(atoi(argv[1]));
    printf("ret:%d\n", ret);
    return 0;
}
