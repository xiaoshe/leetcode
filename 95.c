#include "util.h"

// 动态规划，f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-1)*f(0)
typedef struct tree {
    struct TreeNode** data;
    int size;
}Tree;

void init(Tree *t, int size) {
    t->size = size;
    t->data = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * size);
}

// 构造节点
struct TreeNode* make(int val) {
    struct TreeNode* ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    ret->val = val;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

// 复制一颗树
struct TreeNode* copy(struct TreeNode* root, int add_number) {
    if (root == NULL) return NULL;
    struct TreeNode * ret = make(root->val + add_number);
    ret->left = copy(root->left, add_number);
    ret->right = copy(root->right, add_number);
    return ret;
}


// 释放一颗树
void free_a_tree(struct TreeNode* root) {
    if (root == NULL) return;
    free_a_tree(root->left);
    free_a_tree(root->right);
    free(root);
}

struct TreeNode** generateTrees(int n, int* returnSize){
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    // 申请空间，并初始化前2个节点
    Tree *f = (Tree*)malloc(sizeof(Tree) * (n+1));
    init(&f[0], 1);
    f[0].data[0] = NULL;
    init(&f[1], 1);
    f[1].data[0] = make(1);

    for (int i = 2; i <= n; i++) {
        // 先计算数量
        int s = 0;
        for (int j = 0; j < i; j++) {
            s += f[j].size * f[i-j-1].size;
        }
        init(&f[i], s);

        s = 0;
        // 每个节点做根, 左子树节点个数j-1, 右子树节点个数i-j-1
        for (int j = 1; j <= i; j++) {
            Tree *leftp = &f[j-1];
            Tree *rightp = &f[i-j];
            for (int l = 0; l < leftp->size; l++) {
                for (int r = 0; r < rightp->size; r++) {
                    struct TreeNode* root = make(j);
                    root->left = copy(leftp->data[l], 0);
                    root->right = copy(rightp->data[r], j); // 右子树最小值应该为j+1，所以数值差j+1-1=j
                    f[i].data[s++] = root;
                }
            }
        }
    }

    // 释放空间
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < f[i].size; j++) {
            free_a_tree(f[i].data[j]);
        }
    }
    struct TreeNode** ret = f[n].data;
    *returnSize = f[n].size;
    free(f);
    return ret;
}



int main(int argc, char *argv[]) {
    int size;
    
    int n = atoi(argv[1]);
    struct TreeNode **ret = generateTrees(n, &size);
    printf("size:%d\n", size);
    for (int i = 0; i < size; i++) {
        printf("tree%d:\n", i);
        print_tree(ret[i]);
    }
    return 0;
}
