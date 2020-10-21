#include "util.h"

int isLongPressedName(char * name, char * typed){
    char *p1 = name, *p2 = typed;
    if (*p1++ != *p2++) return 0;
    while (*p1 != 0) {
        char pre = *(p1-1);
        if (*p1 != pre) {
            while (*p2 == pre) p2++;
        }
        if (*p1 != *p2) return 0;
        else p1++, p2++;
    }
    char pre = *(p2-1);
    while (*p2 != 0) {
        if (*p2 != pre) return 0;
        p2++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    char *s1 = "a";
    char *s2 = "ab";
    s1 = "alex";
    s2 = "aaleex";
    s1 = "saeed";
    s2 = "ssaaedd";
    s1 = "leelee";
    s2 = "lleeelee";
    int ret = isLongPressedName(s1, s2);
    printf("ret:%d\n", ret);

    return 0;
}
