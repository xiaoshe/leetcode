#include "util.h"

int rotateString(char * A, char * B){
    int la = strlen(A);
    int lb = strlen(B);
    if (la != lb) return 0;

    char *t = (char*)malloc(la*2+1);
    strcpy(t, A);
    strcpy(t+la, A);
    char *p = strstr(t, B);
    free(t);
    return p != NULL;
}

int main(int argc, char *argv[]) {
    int ret = rotateString(argv[1], argv[2]);
    printf("ret:%d\n", ret);
    return 0;
}
