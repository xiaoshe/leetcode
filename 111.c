#include <stdio.h>
#include <limits.h>
#include "util.h"

int minDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    if (root->left == NULL) {
        if (root->right == NULL) {
            return 1;
        } else {
            return 1 + minDepth(root->right);
        }
    } else {
        if (root->right == NULL) {
            return 1 + minDepth(root->left);
        } else {
            int left = 1 + minDepth(root->left);
            int right = 1 + minDepth(root->right);
            return left < right ? left : right;
        }
    }
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct TreeNode* left = init_tree(a, n);
    print_tree_middle(left);

    int ret = minDepth(left);
    printf("%d\n", ret);
}
