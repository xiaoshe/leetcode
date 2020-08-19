#include "util.h"

static char *key[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char ** letterCombinations(char * digits, int* returnSize){
    // 先计算返回大小，及每个字符串的大小
    int size = 1;
    char *p = digits;
    int len = 0;
    while (*p != 0) {
        if (*p == '7' || *p == '9') {
            len++;
            size *= 4;
        } else if (*p >= '2' && *p < '9') {
            len++;
            size *= 3;
        }
        p++;
    }
    if (size == 1) {
        *returnSize = 0;
        return NULL;
    }

    // 申请空间
    *returnSize = size;
    char **ret = (char **) malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        char *r = (char *)malloc(len+1);
        r[len] = 0;
        ret[i] = r;
    }

    // 穷举所有情况，均匀分散每个数字对应的字母，一个数字一个数字的处理。
    // 计算出每个连续字母的个数
    // 假如有"ab" * "cde"，第1列连续字母个数为3(=size/len("ab"))，第2列连续字母个数为1(=3/len("cde"))，到1结束
    // 0 1
    // a c
    // a d
    // a e
    // b c
    // b d
    // b e
    p = digits;
    int count = size;
    int col = 0;
    while (*p != 0) {
        if (*p >= '2' && *p <= '9') {
            if (*p == '7' || *p == '9') {
                count = count / 4;
            } else {
                count = count / 3;
            }
            // 将字符串key[*p - '0']复制到ret空间上，每个字符重复count个
            int row = 0;
            char *t = key[*p - '0'];
            while (row < size) {
                for (int i = 0; i < count; i++) {
                    ret[row++][col] = *t;
                }
                t++;
                if (*t == 0) {
                    t = key[*p - '0'];
                }
            }
            col++;
        }
        p++;
    }
    return ret;
}


int main(int argc, char *argv[]) {
    int sz = 0;
    char **ret = letterCombinations(argv[1], &sz);
    for (int i = 0; i < sz; i++) {
        printf("%s ", ret[i]);
    }
    return 0;
}
