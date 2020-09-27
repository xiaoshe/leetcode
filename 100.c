#include <stdio.h>
#include <limits.h>
#include "util.h"


int isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL) return q == NULL;
    if (q == NULL) return 0;
    if (p->val != q->val) return 0;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct TreeNode* left = init_tree(a, n);
    print_tree(left);

    n = string_to_array(argv[2], a);
    struct TreeNode* right = init_tree(a, n);
    print_tree(right);

    int ret = isSameTree(left, right);
    printf("%d\n", ret);
}
