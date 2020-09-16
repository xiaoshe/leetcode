#include "util.h"


typedef struct Queue {
    int size;
    struct TreeNode* data[128];
}Queue;

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    double *ret = (double*)malloc(sizeof(double) * 2048);
    int retsize = 0;
    *returnSize = 0;

    Queue a, b;
    Queue *cur = &a, *next = &b;
    cur->size = 0;
    cur->data[cur->size++] = root;
    while (cur->size > 0) {
        double sum = 0;
        next->size = 0;
        for (int i = 0; i < cur->size; i++) {
            struct TreeNode *t = cur->data[i];
            sum += t->val;
            if (t->left != NULL) next->data[next->size++] = t->left;
            if (t->right != NULL) next->data[next->size++] = t->right;
        }
        ret[retsize++] = sum / cur->size;
        Queue *tmp = cur; cur = next; next = tmp; // 交换2个队列
    }
    *returnSize = retsize;
    return ret;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct TreeNode* left = init_tree(a, n);
    print_tree_middle(left);

    int sz = 0;
    double *ret = averageOfLevels(left, &sz);
    printf("size:%d\n", sz);
    for (int i = 0; i < sz; i++) {
        printf("%f\n", ret[i]);
    }

    return 0;
}
