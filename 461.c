#include "util.h"

int hammingDistance(int x, int y){
    int z = x ^ y;
    int c = 0;
    while (z > 0) {
        if (z & 1 == 1) c++;
        z = z>>1;
    }
    return c;
}

int main(int argc, char *argv[]) {
    int ret = hammingDistance(atoi(argv[1]), atoi(argv[2]));
    printf("ret:%d\n", ret);
    return 0;
}
