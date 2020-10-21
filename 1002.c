#include "util.h"

char ** commonChars(char ** A, int ASize, int* returnSize){
    int c[26][101] = {0};
    for (int i = 0; i < ASize; i++) {
        char *p = A[i];
        while (*p != 0) {
            c[*p++ - 'a'][i]++;
        }
    }

    // 统计输出
    int sz = 0;
    char **ret = (char**)malloc(sizeof(char*) * 102);
    for (int i = 0; i < 26; i++) {
        int min = c[i][0];
        for (int j = 1; j < ASize; j++) {
            if (c[i][j] < min) min = c[i][j];
            if (min == 0) break;
        }
        for (int j = 0; j < min; j++) {
            char *t = (char*)malloc(2);
            t[0] = i+'a';
            t[1] = 0;
            ret[sz++] = t;
        }
    }
    *returnSize = sz;
    return ret;
}

int main(int argc, char *argv[]) {
    char *a[3] = {"bella","label","roller"};
    int sz;
    char **ret = commonChars(a, 3, &sz);
    print_string(ret, sz);
    return 0;
}
