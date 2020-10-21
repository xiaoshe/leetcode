#include "util.h"

int countNodes(struct TreeNode* root){
    if (root == NULL) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main(int argc, char *argv[]) {
    char *s = "1,2,3,4,5,6";
    struct TreeNode* root = init_tree(s);
    int ret = countNodes(root);
    printf("ret:%d\n", ret);

    return 0;
}
