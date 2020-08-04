#include <stdio.h>
#include <malloc.h>
#include <limits.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    int p = 0;
    if (strsSize > 0) {
        while (1) {
            char ch = strs[0][p];
            if (ch == 0) break;
            int same = 1;
            for (int i = 1; i < strsSize; i++) {
                if (ch != strs[i][p]) {
                    same = 0;
                    break;
                }
            }
            if (same == 0) break;
            p++;
        }
    }
    printf("p:%d\n", p);
    char *ret = (char *)malloc(p+1);
    if (p > 0) {
        for (int i = 0; i < p; i++) {
            ret[i] = strs[0][i];
        }
    }
    ret[p] = 0;
    return ret;
}

int main(int argc, char *argv[]) {
    char *str[3] = {"dog","racecar","car"};
    //char *str[3] = {"flower","flow","flight"};
    for (int i = 0; i < 3; i++) {
        printf("%s\n", str[i]);
    }
    char *ret = longestCommonPrefix(str, 3);
    printf("ret:%s\n", ret);
}
