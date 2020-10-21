#include "util.h"

#define Node TreeNode

struct Node* connect(struct Node* root) {
    struct Node *y = root; // 纵
    while (y) {
        if (y->left == NULL) break;
        struct Node *x = y;
        while (x) { // 横
            x->left->next = x->right;
            if (x->next) x->right->next = x->next->left;
            x = x->next;
        }
        y = y->left;
    }
    return root;
}

int main(int argc, char *argv[]) {
    // 树
    char *s = "1,2,3,4,5,6,7";
    struct TreeNode *root = init_tree(s);
    print_tree(root);

    struct Node *ret = connect(root);
    while (ret) {
        struct Node *p = ret;
        while (p) {
            printf("%d ", p->val); 
            p = p->next;
        }
        printf("\n");
        ret = ret->left;
    }

    return 0;
}
