#include <stdio.h>
#include <limits.h>
#include "util.h"

int symmetric(struct TreeNode *left, struct TreeNode *right) {
    if (left == NULL) return right == NULL;
    if (right == NULL) return 0;
    if (left->val != right->val) return 0;
    return symmetric(left->left, right->right) && symmetric(left->right, right->left);
}

int isSymmetric(struct TreeNode* root){
    if (root == NULL) return 1;
    return symmetric(root->left, root->right);
}


int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    print_array(a, n);

    struct TreeNode* root = init_tree(a, n);
    print_tree_middle(root);

    int ret = isSymmetric(root);
    printf("%d\n", ret);
}
