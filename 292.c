#include "util.h"

int canWinNim(int n){
    return n % 4 != 0;
}

int main(int argc, char *argv[]) {
    int ret = canWinNim(atoi(argv[1]));
    printf("ret:%d\n", ret);
    return 0;
}
