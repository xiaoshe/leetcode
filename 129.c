#include "util.h"

/*
void change(struct TreeNode* n) {
    if (n == NULL) return;
    if (n->left != NULL) {
        n->left->val += n->val * 10;
        change(n->left);
    }
    if (n->right != NULL) {
        n->right->val += n->val * 10;
        change(n->right);
    }
}

void sum(struct TreeNode* n, int *ret) {
    if (n == NULL) return;
    if (n->left == NULL && n->right == NULL) *ret += n->val;
    sum(n->left, ret);
    sum(n->right, ret);
}

int sumNumbers(struct TreeNode* root){
    // 先改变每个节点上的val
    change(root);
    int ret = 0;
    // 在递归累加每个叶子节点的val
    sum(root, &ret);
    return ret;
}
*/

void sum(struct TreeNode* n, int parent, int *ret) {
    if (n == NULL) return;
    int cur = parent * 10 + n->val;
    if (n->left == NULL && n->right == NULL) *ret += cur;
    sum(n->left, cur, ret);
    sum(n->right, cur, ret);
}

// 方法二：不改变节点val
int sumNumbers(struct TreeNode* root){
    int ret = 0;
    sum(root, 0, &ret);
    return ret;
}


int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    print_array(a, n);

    struct TreeNode* root = init_tree(a, n);
    print_tree(root);

    int ret = sumNumbers(root);
    print_tree(root);
    printf("%d\n", ret);
    return 0;
}
