#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

static char *str[32] = {"", "1", NULL};
static int pos = 1;

char *countAndSay(int n){
    while (n > pos) {
        char *p = str[pos];
        int len = strlen(p);
        char *t = (char *)malloc(len * 2 + 1);
        char *to = t;

        char ch = *p;
        int count = 1;
        for (int i = 1; i < len; i++) {
            if (p[i] == ch) {
                ++count;
            } else {
                *to++ = count + '0';
                *to++ = ch;
                ch = p[i];
                count = 1;
            }
        }
        *to++ = count + '0';
        *to++ = ch;
        *to = 0;
        str[++pos] = t;
    }
    return str[n];
}

int main(int argc, char *argv[]) {
    char *s = countAndSay(atoi(argv[1]));
    printf("%s\n", s);

    for (int i = 0; i < 32; i++) {
        if (str[i] == NULL) {
            printf("NULL\n");
        } else {
            printf("%s\n", str[i]);
        }
    }
}
