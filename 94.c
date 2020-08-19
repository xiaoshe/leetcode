#include <stdio.h>
#include <limits.h>
#include "util.h"


int* inorderTraversal(struct TreeNode* root, int* returnSize){
}

// 递归中序遍历
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct TreeNode* left = init_tree(a, n);
    print_tree_middle(left);

    int sz;
    inorder(left);
}
