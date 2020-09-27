#include "util.h"

// 判断是否是二叉搜索树:左子树小，右子树大
// 中序遍历为升序
static long pre = -9999999999;
int go(struct TreeNode* root){
    if (root == NULL) return 1;
    if (go(root->left) == 0) return 0;
    if (pre >= root->val) return 0;
    pre = root->val;
    if (go(root->right) == 0) return 0;
    return 1;
}
int isValidBST(struct TreeNode* root){
    pre = -9999999999;
    return go(root);
}

int main(int argc, char *argv[]) {
    char *s = "5,1,4,null,null,3,6";
    s = "0";
    struct TreeNode* left = init_tree(s);
    print_tree(left);

    int ret = isValidBST(left);
    printf("ret:%d\n", ret);
    return 0;
}
