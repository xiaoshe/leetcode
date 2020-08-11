#include "util.h"

static int *map[34] = {NULL};
static int pos = -1;

int* getRow(int rowIndex, int* returnSize){
    while (pos < rowIndex) {
        pos++;
        int sz = pos + 1;
        int *t = (int *) malloc(sz * sizeof(int));
        t[0] = 1;
        t[pos] = 1;
        for (int i = 1; i < pos; i++) {
            t[i] = map[pos-1][i] + map[pos-1][i-1];
        }
        map[pos] = t;
    }
    *returnSize = rowIndex + 1;
    int *ret = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = map[rowIndex][i];
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int ret = 0;
    int *a = getRow(atoi(argv[1]), &ret);
    print_array(a, ret);
    return 0;
}
