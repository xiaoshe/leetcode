#include "util.h"

// 要猜的数字
static int g = 0;

int guess(int num) {
    if (num == g) return 0;
    if (g < num) return -1;
    return 1;
}

int guessNumber(int n) {
    int i = 1, j = n;
    while (i < j) {
        // 注意int溢出，所以先除2再加
        int mid = (i>>1) + (j>>1);
        printf("mid:%d\n", mid);
        int ret = guess(mid);
        if (ret == 0) {
            return mid;
        } else if (ret < 0) {
            // 注意边界问题
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    return i;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    g = atoi(argv[2]);
    printf("n:%d g:%d\n", n, g);

    int ret = guessNumber(n);
    printf("ret:%d\n", ret);
    return 0;
}
