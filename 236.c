#include "util.h"

typedef struct path {
    struct TreeNode* data[10000];
    int size;
}Path;
int ok = 0;

void go(struct TreeNode* root, int key, Path *p) {
    if (ok == 1) return;
    p->data[p->size++] = root;
    if (root->val == key) {
        ok = 1;
        return;
    }
    if (root->left) go(root->left, key, p);
    if (root->right) go(root->right, key, p);
    if (ok == 0) p->size--;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    Path a;
    a.size = 0;
    ok = 0;
    go(root, p->val, &a);

    Path b;
    b.size = 0;
    ok = 0;
    go(root, q->val, &b);

    struct TreeNode *ret = a.data[0];
    int i = 1, j = 1;
    while (i < a.size && j < b.size) {
        if (a.data[i]->val != b.data[j]->val) {
            break;
        }
        ret = a.data[i];
        i++, j++;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    char *s = "3,5,1,6,2,0,8,null,null,7,4";
    struct TreeNode p;
    p.val = 5;
    struct TreeNode q;
    q.val = 8;

    struct TreeNode* root = init_tree2(s);
    print_tree(root);
    struct TreeNode* ret = lowestCommonAncestor(root, &p, &q);
    printf("ret:%d\n", ret->val);

    return 0;
}
