#include "util.h"

#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
    int s1 = (C - A) * (D - B);
    int s2 = (G - E) * (H - F);
    if (E>C || G<A || F>D || H<B) return s1 + s2;
    int x1 = max(A, E);
    int y1 = max(B, F);
    int x2 = min(C, G);
    int y2 = min(D, H);
    return s1 - (x2 - x1) * (y2 - y1) + s2;
}

int main(int argc, char *argv[]) {

    int ret = computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
    printf("ret:%d\n", ret);
    return 0;
}
