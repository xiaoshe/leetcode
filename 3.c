#include <stdio.h>
#include <limits.h>
#include <string.h>


int lengthOfLongestSubstring(char * s){
    int exist[256] = {};
    char *begin = s;
    char *end = begin;
    int max = 0;
    while (*end != 0) {
        if (exist[*end] == 1) {
            int t = end - begin;
            if (t > max) max = t;
            // 调整begin，找到和end相同的字符的后一个
            while (begin != end && *begin != *end) exist[*begin++] = 0;
            exist[*begin++] = 0;
        }
        exist[*end++] = 1;
    }
    int t = end - begin;
    if (t > max) max = t;
    return max;
}

int main(int argc, char *argv[]) {
    int ret = lengthOfLongestSubstring(argv[1]);
    printf("ret:%d\n", ret);
}
