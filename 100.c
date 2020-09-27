#include <stdio.h>
#include <limits.h>
#include "util.h"


int isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL) return q == NULL;
    if (q == NULL) return 0;
    if (p->val != q->val) return 0;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char *argv[]) {
    char *l = "1,2,3";
    char *r = "1,2,3";

    l = "1,2";
    r = "1,null,2";

    l = "1,2,1";
    r = "1,1,2";

    struct TreeNode* left = init_tree(l);
    print_tree(left);
    struct TreeNode* right = init_tree(r);
    print_tree(right);

    int ret = isSameTree(left, right);
    printf("%d\n", ret);
}
