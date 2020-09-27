#include "util.h"

int hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) return 0;
    if (root->left == NULL) {
        if (root->right == NULL) {
            return root->val == sum;
        } else {
            return hasPathSum(root->right, sum - root->val);
        }
    } else {
        if (root->right == NULL) {
            return hasPathSum(root->left, sum - root->val);
        } else {
            int n = sum - root->val;
            return hasPathSum(root->left, n) || hasPathSum(root->right, n);
        }
    }
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct TreeNode* left = init_tree(a, n);
    print_tree(left);

    int ret = hasPathSum(left, atoi(argv[2]));
    printf("%d\n", ret);
}
