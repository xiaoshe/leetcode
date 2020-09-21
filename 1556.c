#include "util.h"


char * thousandSeparator(int n){
    if (n == 0) {
        char *ret = (char *)malloc(2);
        ret[0] = '0';
        ret[1] = 0;
        return ret;
    }
    char s[32];
    s[31] = 0;
    int p = 30;
    int c = 0;
    while (n > 0) {
        int m = n % 10;
        s[p--] = '0' + m;
        n /= 10;
        if (++c % 3 == 0) {
            s[p--] = '.';
        }
    }
    p++;
    if (s[p] == '.') p++;
    char *ret = (char *)malloc(32);
    strcpy(ret, s + p);
    return ret;
}
int main(int argc, char *argv[]) {
    // 1,3,5,7,9,11 - 5,3,1,1,3,5
    // 1,3,5,7,9    - 4,2,0,2,4
    char *ret = thousandSeparator(atoi(argv[1]));
    printf("ret:%s\n", ret);
    return 0;
}
