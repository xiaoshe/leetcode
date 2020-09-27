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
    char *s = "1,2,2,3,4,4,3";
    s = "1,2,2,null,3,null,3";
    struct TreeNode* root = init_tree(s);
    print_tree(root);

    int ret = isSymmetric(root);
    printf("%d\n", ret);
}
