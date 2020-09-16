#include "util.h"


int threeConsecutiveOdds(int* arr, int arrSize){
    int n = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] & 1 == 1) {
            if (++n == 3) return 1;
        } else {
            n = 0;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return 0;
}
