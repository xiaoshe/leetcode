#include <stdio.h>
#include <limits.h>
#include "util.h"

// 返回最大高度n，当不平衡时返回-1
int height(struct TreeNode* n) {
    if (n == NULL) return 0;
    int left = height(n->left);
    int right = height(n->right);
    int d = left - right;
    if (left >= 0 && right >= 0 && (d >= -1 && d <= 1)) {
        return left < right ? right + 1 : left + 1;
    } else {
        return -1;
    }
}

int isBalanced(struct TreeNode* root) {
    return height(root) >= 0;
}

int main(int argc, char *argv[]) {
    struct TreeNode* left = init_tree(argv[1]);
    print_tree(left);

    int ret = isBalanced(left);
    printf("%d\n", ret);
}
