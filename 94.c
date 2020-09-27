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
    struct TreeNode* left = init_tree(argv[1]);
    print_tree(left);

    int sz;
    inorder(left);
}
