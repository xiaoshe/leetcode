#include "util.h"

// 判断是否是二叉搜索树:左子树小，右子树大
// 中序遍历为升序
static long pre = -9999999999;
int isValidBST(struct TreeNode* root){
    if (root) {
        if (!isValidBST(root->left)) return 0;
        if (pre >= root->val) return 0;
        pre = root->val;
        if (!isValidBST(root->right)) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    printf("%ld\n", pre);
    int a[32];
    int n = string_to_array(argv[1], a);
    print_array(a, n);
    struct TreeNode* left = init_tree(a, n);
    print_tree_middle(left);

    int ret = isValidBST(left);
    printf("ret:%d\n", ret);
    return 0;
}
