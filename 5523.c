#include "util.h"

int minOperations(char ** logs, int logsSize){
    int level = 0;
    for (int i = 0; i < logsSize; i++) {
        char *l = logs[i];
        if (strcmp(l, "./") == 0) continue;
        if (strcmp(l, "../") == 0) {
            if (level > 0) level--;
        } else {
            level++;
        }
    }
    return level;
}

int main(int argc, char *argv[]) {
    /*
    char *s[32] = {"d1/","d2/","../","d21/","./"};
    int sz = 5;
    char *s[32] = {"d1/","d2/","./","d3/","../","d31/"};
    int sz = 6;
    */
    char *s[32] = {"d1/","../","../","../"};
    int sz = 4;
    int ret = minOperations(s, sz);
    printf("ret:%d\n", ret);
    return 0;
}
