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

struct Node* connect(struct Node* root) {
    if (root == NULL) return NULL;

    struct Node* queue[6000];
    int start = 0, end = 0;
    queue[end++] = root;

    // 广度，先放右孩子，再放左孩子
    while (start < end) {
        int s = end, e = end;
        for (int i = start; i < end; i++) {
            struct Node* p = queue[i];
            if (p->right != NULL) queue[e++] = p->right;
            if (p->left != NULL) queue[e++] = p->left;
            if (i > start) {
                p->next = queue[i-1];
            }
        }
        start = s;
        end = e;
    }
    return root;
}

/*
// TODO:递归未通过
// [1,2,3,4,5,null,6,7,null,null,null,null,8]
struct Node* find(struct Node* cur) {
    struct Node* p = cur;
    while (p) {
        if (p->left) return p->left;
        if (p->right) return p->right;
        p = p->next;
    }
    return NULL;
}
void go(struct Node* root, struct Node* next) {
    root->next = next;
    if (root->left) {
        struct Node* n = root->right;
        if (!n) n = find(next);
        go(root->left, n);
    }
    if (root->right) {
        go(root->right, find(next));
    }
    if (next) {
        if (next->left) go(next->left, next->right);
    }
}
struct Node* connect(struct Node* root) {
    if (root == NULL) return NULL;

    go(root, NULL);
    return root;
}
*/

int main(int argc, char *argv[]) {
    // 树
    char *s = "1,2,3,4,5,null,7";
    struct Node *root = init(s);

    root = connect(root);

    return 0;
}
