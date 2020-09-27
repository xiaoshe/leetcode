#include "util.h"


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (root->val == p->val || root->val == q->val) return root;
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL) return root;
    return left == NULL ? right : left;
}

int main(int argc, char *argv[]) {
    char *s = "3,5,1,6,2,0,8,null,null,7,4";
    struct TreeNode p;
    p.val = 7;
    struct TreeNode q;
    q.val = 4;

    struct TreeNode* root = init_tree(s);
    print_tree(root);
    struct TreeNode* ret = lowestCommonAncestor(root, &p, &q);
    printf("ret:%d\n", ret->val);

    return 0;
}
