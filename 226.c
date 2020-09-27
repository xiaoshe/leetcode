#include "util.h"


struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return NULL;
    struct TreeNode *t = root->left;
    root->left = root->right;
    root->right = t;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct TreeNode* left = init_tree(a, n);
    print_tree(left);
    struct TreeNode* ret = invertTree(left);
    print_tree(ret);
    return 0;
}
