#include "util.h"

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if (t1 == NULL && t2 == NULL) return NULL;
    struct TreeNode *t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t->val = 0;
    if (t1) t->val += t1->val;
    if (t2) t->val += t2->val;
    t->left = mergeTrees(t1 == NULL ? t1 : t1->left, t2 == NULL ? t2 : t2->left);
    t->right = mergeTrees(t1 == NULL ? t1 : t1->right, t2 == NULL ? t2 : t2->right);
    return t;
}

int main(int argc, char *argv[]) {
    char *s1 = "1,3,2,5";
    struct TreeNode* t1 = init_tree2(s1);
    char *s2 = "2,1,3,null,4,null,7";
    struct TreeNode* t2 = init_tree2(s2);
    print_tree(t1);
    print_tree(t2);

    struct TreeNode* ret = mergeTrees(t1, t2);
    print_tree(ret);

    return 0;
}
