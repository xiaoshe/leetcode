#include "util.h"

char * simplifyPath(char * path){
    int sz = strlen(path);
    if (sz == 0) return NULL;
    char *ret = (char*)malloc(sz + 1);
    sz = 0;
    char *p = path+1;
    int valid = 1;
    while (valid) {
        // 从'/'开始
        char *s = p;
        while (*p != 0 && *p != '/') p++;
        if (*p == 0) valid = 0;
        char *e = p++;

        int l = e - s;
        if (l == 0) continue;
        if (l == 1 && *s == '.') continue;
        if (l == 2 && *s == '.' && *(s+1) == '.') {
            // 回退
            while (sz > 0 && ret[sz-1] != '/') sz--;
            if (sz > 0) sz--;
            continue;
        }
        ret[sz++] = '/';
        for (char *t = s; t != e; t++) {
            ret[sz++] = *t;
        }
    }
    if (sz == 0) ret[sz++] = '/';
    ret[sz] = 0;
    return ret;
}

int main(int argc, char *argv[]) {
    char *ret = simplifyPath(argv[1]);
    printf("ret:%s\n", ret);

    return 0;
}
