#include <stdio.h>
#include <limits.h>
#include "util.h"

static int sum = 0;

void add(struct TreeNode* root) {
    if (root == NULL) return;
    if (root->left != NULL) {
        if (root->left->left == NULL && root->left->right == NULL) sum += root->left->val;
        add(root->left);
    }
    add(root->right);
}

// 递归
int sumOfLeftLeaves(struct TreeNode* root){
    sum = 0;
    add(root);
    return sum;
}


int main(int argc, char *argv[]) {
    struct TreeNode* left = init_tree(argv[1]);
    print_tree(left);

    int ret = sumOfLeftLeaves(left);
    printf("%d\n", ret);
}
