#ifndef UTIL_H_
#define UTIL_H_

#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

// 字符串转数组
// ret数组要足够大，返回数组大小
int string_to_array(char *s, int ret[]) {
    int n = 0;
    while (*s != 0) {
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
struct ListNode *init(int a[], int n) {
    struct ListNode *ret = NULL;
    for (int i = n - 1; i >= 0; i--) {
        struct ListNode *t = make(a[i]);
        t->next = ret;
        ret = t;
    }
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
    struct TreeNode *ret[32];
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

void print_tree_middle(struct TreeNode *tree) {
    /*
    struct TreeNode *s[32] = {NULL};
    int tail = 0;
    if (tree != NULL) {
        s[tail++] = tree;
    }

    int head = 0;
    while (s[head] != NULL) {
        printf("%d ", s[head]->val);
        if (s[head]->left != NULL) {
            s[tail++] = s[head]->left;
        }
        if (s[head]->right != NULL) {
            s[tail++] = s[head]->right;
        }
        head++;
    }
    printf("\n");
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

#endif
