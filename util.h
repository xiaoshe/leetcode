#ifndef UTIL_H_
#define UTIL_H_

#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>

// 字符串转数组
// ret数组要足够大，返回数组大小
int string_to_array(char *s, int ret[]) {
    int n = 0;
    while (*s != 0 && *s != '\n') {
        int number = 0;
        int pos = 1; // 默认：正数
        while (*s != '-' && !isdigit(*s)) s++;
        if (*s == '-') {
            pos = 0;
            s++;
        }
        while (isdigit(*s)) {
            number = number * 10 + *s - '0';
            s++;
        }
        if (pos == 1) {
            ret[n++] = number;
        } else {
            ret[n++] = 0 - number;
        }
    }
    return n;
}

// 打印数组
void print_array(int a[], int n) {
    printf("Array[%d]:", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int **array(int a[][32], int m, int n) {
    int **ret = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        int *t = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            t[j] = a[i][j];
        }
        ret[i] = t;
    }
    return ret;
}

// 单链表
struct ListNode {
    int val;
    struct ListNode *next;
};

// 创建单链表节点
struct ListNode *make(int v) {
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = v;
    p->next = NULL;
    return p;
}

// 根据数组创建一条单链表
struct ListNode *init_list(int a[], int n) {
    struct ListNode *ret = NULL;
    for (int i = n - 1; i >= 0; i--) {
        struct ListNode *t = make(a[i]);
        t->next = ret;
        ret = t;
    }
    return ret;
}

struct ListNode *tail_list(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* ret = head;
    while (ret->next != NULL) ret = ret->next;
    return ret;
}

// 打印单链表
void print_list(struct ListNode* l) {
    while (l != NULL) {
        printf("%d -> ", l->val);
        l = l->next;
    }
    printf(" ^\n");
}

// 栈
#define SIZE 64
struct Stack {
    int val[SIZE];
    int top;
};

// 二叉树节点
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct TreeNode *make_tree_node(int v) {
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->val = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// 根据数组创建满二叉树，元组0表示NULL
struct TreeNode *init_tree(int a[], int sz) {
    struct TreeNode *ret[SIZE];
    for (int i = 0; i < sz; i++) {
        struct TreeNode *t = NULL;
        if (a[i] != 0) {
            t = make_tree_node(a[i]);
        }
        ret[i] = t;
    }
    for (int i = 0; i < sz; i++) {
        struct TreeNode *t = ret[i];
        int left = i * 2 + 1;
        if (left < sz && ret[left] != NULL) {
            t->left = ret[left];
        }
        int right = i * 2 + 2;
        if (right < sz && ret[right] != NULL) {
            t->right = ret[right];
        }
    }
    return ret[0];
}

// 1,2,3,null,4,5
struct TreeNode *init_tree2(char *s) {
    struct TreeNode *ret[SIZE] = {NULL};
    int sz = 0;
    while (*s != 0) {
        if (*s >= '0' && *s <= '9') {
            int val = 0;
            while (*s >= '0' && *s <= '9') {
                val = val * 10 + *s - '0';
                s++;
            }
            struct TreeNode *t = make_tree_node(val);
            ret[sz++] = t;
        } else if (*s == 'n') {
            // null
            s += 4;
            sz++;
        }
        if (*s == ',') s++;
    }
    for (int i = 0; i < sz; i++) {
        struct TreeNode *t = ret[i];
        int left = i * 2 + 1;
        if (left < sz) t->left = ret[left];
        int right = i * 2 + 2;
        if (right < sz) t->right = ret[right];
    }
    return ret[0];
}

void print_tree_middle(struct TreeNode *tree) {
    /*
    */
    // 树状打印
    struct TreeNode *s1[SIZE] = {NULL};
    int l1 = 0;
    struct TreeNode *s2[SIZE] = {NULL};
    int l2 = 0;
    if (tree != NULL) {
        s1[l1++] = tree;
    }
    while (1) {
        int empty = 1;
        for (int i = 0; i < l1; i++) {
            if (s1[i] != NULL) {
                empty = 0;
                break;
            }
        }
        // 全空
        if (empty == 1) {
            printf("tree ok\n");
            break;
        }

        l2 = 0;
        for (int i = 0; i < l1; i++) {
            if (s1[i] == NULL) {
                printf("- ");
                // 左右孩子
                s2[l2++] = NULL;
                s2[l2++] = NULL;
            } else {
                printf("%d ", s1[i]->val);
                // 左右孩子
                s2[l2++] = s1[i]->left;
                s2[l2++] = s1[i]->right;
            }
        }
        printf("\n");

        for (int i = 0; i < l2; i++) {
            s1[i] = s2[i];
        }
        l1 = l2;
    }
}

void print_tree(struct TreeNode *tree) {
    // 树状打印，最多6行，每个数字占4个字节
    // 先计算x行
    struct TreeNode *copy[SIZE] = {tree};
    int head = 0; // 含
    int tail = 1; // 不含
    int level = 0;
    while (head < tail) {
        // 判断是否全空
        int null = 0;
        for (int i = head; i < tail; i++) {
            if (copy[i] != NULL) {
                null = 1;
                break;
            }
        }
        if (null == 0) break;
        level++;
        int h = head;
        int t = tail;
        for (int i = h; i < t; i++) {
            if (copy[i] != NULL) {
                copy[tail++] = copy[i]->left;
                copy[tail++] = copy[i]->right;
            } else {
                copy[tail++] = NULL;
                copy[tail++] = NULL;
            }
        }
        head = t;
    }
    int nums[6] = {1,2,4,8,16,32}; // 第x行数字个数
    int ptr[6] = {0,1,3,7,15,31};  // 第x行开始位置
    int maxlen = nums[level] * 3;

    // 针对每行数字个数计算每个数字占据字符数
    char *ret[6] = {NULL};
    for (int i = level-1; i >= 0; i--) {
        char *str = (char *)malloc(maxlen+1);
        char *s = str;
        int avg = maxlen / nums[i]; // 每个数字宽度
        int pos = ptr[i];
        for (int j = 0; j < nums[i]; j++) {
            struct TreeNode *p = copy[j+pos];
            if (p == NULL) {
                for (int k = 0; k < avg; k++) *s++ = ' ';
            } else {
                // 数字居中
                char v[32];
                sprintf(v, "%d", p->val);
                int l = strlen(v);
                int left = (avg - l)/2;
                for (int k = 0; k < left; k++) *s++ = ' ';
                for (int k = 0; k < l; k++) *s++ = v[k];
                int right = avg - l - left;
                for (int k = 0; k < right; k++) *s++ = ' ';
            }
        }
        ret[i] = str;
    }

    for (int i = 0; i < level; i++) {
        printf("%s\n", ret[i]);
    }
}


#endif
