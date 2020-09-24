#include "util.h"

char * getPermutation(int n, int k){
    int nums[10] = {0}; // nums[i]:代表i的阶乘
    nums[1] = 1;
    for (int i = 2; i < 10; i++) nums[i] = nums[i-1] * i;
    print_array(nums, 10);

    char *ret = (char *)malloc(n+1);
    ret[n] = 0;
    for (int i = 0; i < n; i++) ret[i] = i+1+'0';
    printf("raw:%s\n", ret);

    for (int cur = 0; cur < n; cur++) {
        int nu = nums[n - cur - 1];
        // k有几个
        int t = k / nu;
        // 将第t个字符挪至current位置
        char ch = ret[t+cur];
        printf("k:%d num:%d t:%d ch:%c\n", k, nu, t, ch);
        for (int i = t+cur; i>cur; i--) {
            ret[i] = ret[i-1];
        }
        printf("ret:%s\n", ret);
        k -= t * nu;
    }

    return ret;
}

int main(int argc, char *argv[]) {
    {
        char *ret = getPermutation(3, 2);
        printf("ret:%s\n", ret);
    }
    {
        char *ret = getPermutation(4, 9);
        printf("ret:%s\n", ret);
    }
    return 0;
}
