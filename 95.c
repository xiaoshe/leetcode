#include "util.h"

struct TreeNode** ret = NULL;
int sz = 0;

// mid作为根节点
struct TreeNode* go(int mid, int n) {
    if (mid == 1 || mid == n) return NULL;
    struct TreeNode* t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t->val = mid;
    t->left = go():
    t->right = go();
    return t;
}

struct TreeNode** generateTrees(int n, int* returnSize){
    ret = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    sz = 0;
    for (int i = 1; i <= n; i++) {
        go(i, n);
    }

    return ret;
}

int main(int argc, char *argv[]) {
    int sz;
    struct TreeNode** ret = generateTrees(atoi(argv[1]), &sz);
    for (int i = 0; i < sz; i++) {
        print_tree(ret[i]);
        printf("-----------------\n");
    }

    return 0;
}
