#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

char * convert(char * s, int numRows){
    // 转二维数组
    int len = strlen(s);
    char *t = (char *)malloc(len * numRows);

    int i = 0;
    int j = 0;
    int down = 1;
    while (*s != 0) {
        int pos = j * len + i;
        if (down == 1) {
            *(t + pos) = *s;
            j++;
            if (j == numRows) {
                down = 0;
                j -= 2;
                i++;
            }
        } else {
            *(t + pos) = *s;
            i++;
            j--;
            if (j < 0) {
                down = 1;
                i--;
                j += 2;
            }
        }
        s++;
    }


    for (j = 0; j < numRows; ++j) {
        for (i = 0; i < len; ++i) {
            char ch = *(t + j * len + i);
            if (ch == 0) {
                printf(" ");
            } else {
                printf("%c", ch);
            }
        }
        printf("\n");
    }

    // 输出
    char *ret = (char *)malloc(len + 1);
    char *p = ret;
    for (j = 0; j < numRows; ++j) {
        for (i = 0; i < len; ++i) {
            char ch = *(t + j * len + i);
            if (ch != 0) {
                *p++ = ch;
            }
        }
    }
    free(t);
    *p = 0;
    return ret;
    
}

int main(int argc, char *argv[]) {
    char *ret = convert(argv[1], atoi(argv[2]));

    printf("ret:%s\n", ret);
}
