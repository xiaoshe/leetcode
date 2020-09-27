#include <stdio.h>

#include "util.h"


int main(int argc, char *argv[]) {
    /*
    int a[16];
    int n = string_to_array(argv[1], a);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    */
    struct TreeNode *root = init_tree(argv[1]);
    print_tree(root);
    return 0;
}
