#include "util.h"

int depth(struct TreeNode* root) {
    int d = 0;
    while (root) {
        d++;
        root = root->left;
    }
    return d;
}
int countNodes(struct TreeNode* root){
    if (root == NULL) return 0;
    int ld = depth(root->left);
    int rd = depth(root->right);
    if (ld == rd) {
        return (1<<ld) + countNodes(root->right);
    } else {
        return countNodes(root->left) + (1<<rd); 
    }
}

int main(int argc, char *argv[]) {
    char *s = "1,2,3,4,5,6";
    struct TreeNode* root = init_tree(s);
    int ret = countNodes(root);
    printf("ret:%d\n", ret);

    return 0;
}
