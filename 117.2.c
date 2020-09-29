#include "util.h"


struct Node {
	int val;
	struct Node *left;
	struct Node *right;
	struct Node *next;
};

struct Node *make2(int v) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->val = v;
    p->left = NULL;
    p->right = NULL;
    p->next = NULL;
    return p;
}
struct Node *init(char *s) {
    struct Node *ret[SIZE] = {NULL};
    int top = 0, lr = 0;
    int sz = 0;
    int n = 0;
    char **t = split(s, ',', &n);
    if (n == 0) return NULL;
    // 根节点
    ret[sz++] = make2(atoi(t[0]));

    for (int i = 1; i < n; i++) {
        char *p = trim(t[i]);
        struct Node *cur = NULL;
        if (*p != 'n') {
            cur = make2(atoi(p));
        }
        // 将当前节点挂到前面第一个节点上，左或右
        struct Node* pre = ret[top];
        if (lr == 0) {
            pre->left = cur;
            lr = 1;
        } else {
            // 右节点挂上后，取下一个节点top+1
            pre->right = cur;
            lr = 0;
            top++;
        }
        // 当前节点加到ret中
        if (cur != NULL) ret[sz++] = cur;
    }
    return ret[0];
}

struct Node* find(struct Node* p) {
    while (p) {
        if (p->left) return p->left;
        if (p->right) return p->right;
        p = p->next;
    }
    return NULL;
}

struct Node* connect(struct Node* root) {
    if (root == NULL) return NULL;

    struct Node* first = root;
    struct Node* left = first;
    while (1) {
        // second记录下一层的首个节点
        struct Node* second = NULL;
        while (first) {
            if (first->left) {
                second = first->left;
                break;
            }
            if (first->right) {
                second = first->right;
                break;
            }
            first = first->next;
        }
        if (second == NULL) break;

        while (first) {
            // 该节点的2个左右孩子
            if (first->left) {
                if (first->right) first->left->next = first->right; // 亲兄弟
                else first->left->next = find(first->next); // 堂兄弟
            }
            if (first->right) {
                first->right->next = find(first->next);
            }
            first = first->next;
        }
        first = second;
    }
    return root;
}


int main(int argc, char *argv[]) {
    // 树
    char *s = "1,2,3,4,5,null,7";
    struct Node *root = init(s);

    root = connect(root);

    return 0;
}
