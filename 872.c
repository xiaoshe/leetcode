#include "util.h"

void go(struct TreeNode* root, int leaf[], int *sz) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        leaf[*sz] = root->val;
        *sz = *sz + 1;
        return;
    }
    go(root->left, leaf, sz);
    go(root->right, leaf, sz);
}

int leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int leaf1[200];
    int sz1 = 0;
    int leaf2[200];
    int sz2 = 0;

    go(root1, leaf1, &sz1);
    go(root2, leaf2, &sz2);
    print_array(leaf1, sz1);
    if (sz1 != sz2) return 0;
    for (int i = 0; i < sz1; i++) {
        if (leaf1[i] != leaf2[i]) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    char *s1 = "3,5,1,6,2,8,9,-,-,7,4";
    char *s2 = "30,50,10,6,2,8,9,-,-,7,4";

    int a1[32];
    int n1 = string_to_array(s1, a1);
    struct TreeNode* root1 = init_tree(a1, n1);

    int a2[32];
    int n2 = string_to_array(s2, a2);
    struct TreeNode* root2 = init_tree(a2, n2);

    int ret = leafSimilar(root1, root2);
    printf("ret:%d\n", ret);

    return 0;
}
