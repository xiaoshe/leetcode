#include "util.h"


typedef struct stack {
    struct TreeNode* node[200];
    int top;
}Stack;

struct TreeNode* pop_a_leaf(Stack *s) {
    while (s->top != -1) {
        struct TreeNode *n = s->node[s->top--];
        if (n->left == NULL && n->right == NULL) return n;
        if (n->right) s->node[++s->top] = n->right;
        if (n->left) s->node[++s->top] = n->left;
    }
    return NULL;
}

int leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    // 同时进行深度优先
    Stack s1;
    s1.top = -1;
    s1.node[++s1.top] = root1;
    Stack s2;
    s2.top = -1;
    s2.node[++s2.top] = root2;
    /*
    while (1) {
        struct TreeNode* a = pop_a_leaf(&s1);
        if (a == NULL) break;
        printf("%d ", a->val);
    }
    */


    // 遍历root1
    while (1) {
        struct TreeNode* a = pop_a_leaf(&s1);
        struct TreeNode* b = pop_a_leaf(&s2);
        if (a == NULL) {
            if (b == NULL) return 1;
            else return 0;
        } else {
            if (b == NULL || a->val != b->val) return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {
    char *s1 = "3,5,1,6,2,8,9,null,null,7,4";
    char *s2 = "30,50,10,6,2,8,9,null,null,7,4";

    struct TreeNode* root1 = init_tree(s1);
    struct TreeNode* root2 = init_tree(s2);

    int ret = leafSimilar(root1, root2);
    printf("ret:%d\n", ret);

    return 0;
}
