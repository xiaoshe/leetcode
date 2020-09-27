#include "util.h"


/*
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (root->val == p->val || root->val == q->val) return root;
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL) return root;
    return left == NULL ? right : left;
}

// 利用二叉搜索树的特点
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else {
        return root;
    }
}
*/
// 非递归
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int min = p->val;
    int max = q->val;
    if (p->val > q->val) {
        min = q->val;
        max = p->val;
    }

    while (root) {
        if (min > root->val) root = root->right;
        else if (max < root->val) root = root->left;
        else return root;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    char *s = "3,5,1,6,2,0,8,null,null,7,4";
    s = "6,2,8,0,4,7,9,null,null,3,5";
    struct TreeNode p;
    p.val = 2;
    struct TreeNode q;
    q.val = 5;

    struct TreeNode* root = init_tree2(s);
    print_tree(root);
    struct TreeNode* ret = lowestCommonAncestor(root, &p, &q);
    printf("ret:%d\n", ret->val);

    return 0;
}
