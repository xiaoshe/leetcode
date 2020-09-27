#include "util.h"

void trav(struct TreeNode* root, int *ret, int *sz) {
    if (root == NULL) return;
    trav(root->left, ret, sz);
    trav(root->right, ret, sz);
    ret[(*sz)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *ret = (int*)malloc(sizeof(int) * 10000);
    int sz = 0;
    trav(root, ret, &sz);
    *returnSize = sz;
    return ret;
}

int main(int argc, char *argv[]) {
    struct TreeNode* left = init_tree(argv[1]);
    print_tree(left);

    int sz;
    int *ret = postorderTraversal(left, &sz);
    print_array(ret, sz);
    return 0;
}
