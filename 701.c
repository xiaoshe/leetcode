#include "util.h"


struct TreeNode* get(int v) {
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->val = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if (root == NULL) return get(val);

    struct TreeNode* p = root;
    while (1) {
        if (val > p->val) {
            // 右子树
            if (p->right == NULL) {
                p->right = get(val);
                break;
            } else {
                p = p->right;
            }
        } else {
            // 左子树
            if (p->left == NULL) {
                p->left = get(val);
                break;
            } else {
                p = p->left;
            }
        }
    }
    return root;
}

int main(int argc, char *argv[]) {
    // 树
    char *s = "4,2,7,1,3";
    int key = 0;
    struct TreeNode *root = init_tree(s);
    print_tree(root);
    root = insertIntoBST(root, key);
    print_tree(root);



    return 0;
}
