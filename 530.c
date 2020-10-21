#include "util.h"

int min = -1;
int last = -1;
void go(struct TreeNode* root) {
    if (root == NULL) return;
    go(root->left);
    if (last >= 0 && (min < 0 || min > root->val - last)) {
        min = root->val - last;
    }
    last = root->val;
    go(root->right);
}
int getMinimumDifference(struct TreeNode* root){
    min = -1;
    last = -1;
    go(root);
    return min;
}

int main(int argc, char *argv[]) {
    // 树
    char *s = "5,2,13";
    s = "5,1,7";
    s = "0,null,2236,1277,2776,519";
    struct TreeNode *root = init_tree(s);
    print_tree(root);
    int ret = getMinimumDifference(root);
    printf("ret:%d\n", ret);


    return 0;
}
