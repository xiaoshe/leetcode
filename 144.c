#include "util.h"

int *ret = NULL;
int size = 0;
void go(struct TreeNode* root) {
    if (root == NULL) return;
    ret[size++] = root->val;
    go(root->left);
    go(root->right);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    ret = (int*)malloc(sizeof(int)*10000);
    size = 0;
    go(root);
    *returnSize = size;
    return ret;
}

int main(int argc, char *argv[]) {
    struct TreeNode* root = init_tree(argv[1]);
    print_tree(root);
    int sz;
    int *ret = preorderTraversal(root, &sz);
    print_array(ret, sz);

    return 0;
}
