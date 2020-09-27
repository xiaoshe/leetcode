#include "util.h"


typedef struct money {
    int m1; // 抢根节点最大值
    int m2; // 不抢根节点最大值
}Money; 

Money _rob(struct TreeNode* root) {
    if (root == NULL) {
        Money m;
        m.m1 = 0;
        m.m2 = 0;
        return m;
    }
    Money left = _rob(root->left);
    Money right = _rob(root->right);
    Money ret;
    // 抢劫根节点
    ret.m1 = root->val + left.m2 + right.m2;
    // 不抢劫根节点
    ret.m2 = (left.m1 > left.m2 ? left.m1 : left.m2) + (right.m1 > right.m2 ? right.m1 : right.m2);
    return ret;
}

int rob(struct TreeNode* root){
    if (root == NULL) return 0;
    Money ret = _rob(root);
    return ret.m1 > ret.m2 ? ret.m1 : ret.m2;
}

int main(int argc, char *argv[]) {
    struct TreeNode* left = init_tree(argv[1]);
    print_tree(left);
    int ret = rob(left);
    printf("ret:%d\n", ret);
    return 0;
}
