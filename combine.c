#include "util.h"

// 递归输出所有的组合
int stack[32];
int top = -1;
void combine(int data[], int sz, int start) {
    printf("start:%d\n", start);
    for (int i = start; i < sz; i++) {
        stack[++top] = data[i];
        print_array(stack, top+1);
        combine(data, sz, i+1);
        --top;
    }
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    print_array(a, n);

    combine(a, n, 0);
    return 0;
}
