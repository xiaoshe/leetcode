#include "util.h"


int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *ret = (int*)malloc(sizeof(int)*10000);
    int size = 0;

    // stack
    struct TreeNode* stack[10000];
    int top = 0;
    if (root) stack[top++] = root;

    while (top > 0) {
        top--;
        struct TreeNode *p = stack[top];
        ret[size++] = p->val;
        if (p->right) stack[top++] = p->right;
        if (p->left) stack[top++] = p->left;
    }

    *returnSize = size;
    return ret;
}

int main(int argc, char *argv[]) {
    struct TreeNode* root = init_tree(argv[1]);
    print_tree(root);
    int sz;
    int *ret = preorderTraversal(root, &sz);
    print_array(ret, sz);

    return 0;
}
