#include "util.h"

char * restoreString(char * s, int* indices, int indicesSize){
    char *t = (char *)malloc(sizeof(char) * indicesSize);
    for (int i = 0; i < indicesSize; i++) {
        int p = indices[i];
        t[p] = s[i];
    }
    for (int i = 0; i < indicesSize; i++) {
        s[i] = t[i];
    }
    free(t);
    return s;
}

int main(int argc, char *argv[]) {
    char t[32];
    strcpy(t, argv[1]);
    int a[32];
    int n = string_to_array(argv[2], a);
    char *ret = restoreString(t, a, n);
    printf("%s\n", ret);
    return 0;
}
