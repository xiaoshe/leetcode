#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


char * intToRoman(int num){
    char *ret = (char *)malloc(64);
    char *p = ret;
    while (num > 0) {
        if (num >= 1000) {
            *p++ = 'M';
            num -= 1000;
        } else if (num >= 900) {
            *p++ = 'C';
            *p++ = 'M';
            num -= 900;
        } else if (num >= 500) {
            *p++ = 'D';
            num -= 500;
        } else if (num >= 400) {
            *p++ = 'C';
            *p++ = 'D';
            num -= 400;
        } else if (num >= 100) {
            *p++ = 'C';
            num -= 100;
        } else if (num >= 90) {
            *p++ = 'X';
            *p++ = 'C';
            num -= 90;
        } else if (num >= 50) {
            *p++ = 'L';
            num -= 50;
        } else if (num >= 40) {
            *p++ = 'X';
            *p++ = 'L';
            num -= 40;
        } else if (num >= 10) {
            *p++ = 'X';
            num -= 10;
        } else if (num >= 9) {
            *p++ = 'I';
            *p++ = 'X';
            num -= 9;
        } else if (num >= 5) {
            *p++ = 'V';
            num -= 5;
        } else if (num >= 4) {
            *p++ = 'I';
            *p++ = 'V';
            num -= 4;
        } else {
            *p++ = 'I';
            num -= 1;
        }
    }
    *p = 0;
    return ret;
}

int main(int argc, char *argv[]) {
    char *ret = intToRoman(atoi(argv[1]));
    printf("ret:%s\n", ret);
}
