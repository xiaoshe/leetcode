#include "util.h"

// 右中左
void go(struct TreeNode *root, int *sum) {
    if (root == NULL) return;
    go(root->right, sum);
    root->val += *sum;
    *sum = root->val;
    go(root->left, sum);
}
struct TreeNode* convertBST(struct TreeNode* root){
    int sum = 0;
    go(root, &sum);
    return root;
}

int main(int argc, char *argv[]) {
    char *s = "5,2,13";
    s = "5,2,13,1,3,6,15";
    struct TreeNode *root = init_tree(s);
    print_tree(root);
    struct TreeNode *ret = convertBST(root);
    print_tree(ret);
    return 0;
}
