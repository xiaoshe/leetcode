#include "util.h"


void flatten(struct TreeNode* root){
    if (root == NULL) return;
    struct TreeNode* left = root->left;
    if (left == NULL) {
        flatten(root->right);
        return;
    }

    // 右孩子接到左孩子的右侧末尾
    struct TreeNode *p = left;
    while (p->right != NULL) {
        p = p->right;
    }
    p->right = root->right;

    root->left = NULL;
    root->right = left;
    flatten(left);
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);

    struct TreeNode* left = init_tree(a, n);
    print_tree(left);
    flatten(left);
    print_tree(left);

    return 0;
}
