#ifndef UTIL_H_
#define UTIL_H_

#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>

// 字符转整数atoi()，例如" \n -123 " => 123, "abc" => 0
#define SIZE 64

// 重新申请空间
char *trim(char *s) {
    while (isspace(*s)) s++;
    int l = strlen(s);
    char *ret = (char *)malloc(l+1);
    strcpy(ret, s);
    ret[l] = 0;
    while (--l >= 0) {
        if (isspace(ret[l])) {
            ret[l] = 0;
        } else {
            break;
        }
    }
    return ret;
}

// 切分字符串，返回字符串数组，大小为sz
// NOTE:sz最大为SIZE，每个字符串最长为SIZE
char **split(char *s, char seq, int *sz) {
    char **ret = (char **)malloc(sizeof(char*) * SIZE);
    int n = 0;
    while (1) {
        char *r = (char *)malloc(SIZE);
        char *p = strchr(s, seq);
        if (p == NULL) {
            strcpy(r, s);
            ret[n++] = r;
            break;
        } else {
            strncpy(r, s, p - s);
            ret[n++] = r;
            s = p + 1;
        }
    }
    *sz = n;
    return ret;
}

char **extract(char *str, char *begin, char *end, int *sz) {
    char **ret = (char **)malloc(sizeof(char*) * SIZE);
    int blen = strlen(begin);
    int elen = strlen(end);
    int n = 0;
    char *s = str;
    while (1) {
        char *b = strstr(s, begin);
        if (b == NULL) break;
        char *e = strstr(s + blen, end);
        if (e == NULL) break;
        char *r = (char *)malloc(SIZE);
        strncpy(r, b+1, e - b - 1);
        ret[n++] = r;
        s = e + elen;
    }
    *sz = n;
    return ret;
}

// 字符串转数组
// ret数组要足够大，返回数组大小
int string_to_array(char *s, int ret[]) {
    int sz;
    char **t = split(s, ',', &sz);
    for (int i = 0; i < sz; i++) {
        ret[i] = atoi(t[i]);
    }
    return sz;
}

// 打印数组
void print_array(int a[], int n) {
    printf("Array[%d]:", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void print_string(char **a, int n) {
    printf("char**[%d]:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  %s\n", a[i]);
    }
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

// 每个[]对应一个数组，例如：
// s:
//    [1, 2, 3, 4],
//    [5, 6, 7, 8],
//    [9,10,11,12]
// sz: 返回二维数组大小
// sizes：返回每个数组的大小
int **string_array(char *s, int *sz, int **sizes) {
    int **ret = (int**)malloc(sizeof(int*) * SIZE);
    int *sizess = (int *)malloc(sizeof(int) * SIZE);
    int n;
    char **t = extract(s, "[", "]", &n);
    for (int i = 0; i < n; i++) {
        int a[SIZE];
        int al = string_to_array(t[i], a);
        int *r = (int *)malloc(sizeof(int) * SIZE);
        for (int j = 0; j < al; j++) r[j] = a[j];
        ret[i] = r;
        sizess[i] = al;
    }
    *sz = n;
    *sizes = sizess;
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

struct ListNode *init_list(char *s) {
    int sz;
    char **t = split(s, ',', &sz);
    struct ListNode *ret = NULL;
    for (int i = sz - 1; i >= 0; i--) {
        int v = atoi(t[i]);
        struct ListNode *t = make(v);
        t->next = ret;
        ret = t;
    }
    return ret;
}
/*
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
*/


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

/*
// 1,2,3,null,4,5
struct TreeNode *init_tree(char *s) {
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
*/

// 1,2,3,null,4,5
// 1,null,2,2
struct TreeNode *init_tree(char *s) {
    struct TreeNode *ret[SIZE] = {NULL};
    int top = 0, lr = 0;
    int sz = 0;
    int n = 0;
    char **t = split(s, ',', &n);
    if (n == 0) return NULL;
    // 根节点
    ret[sz++] = make_tree_node(atoi(t[0]));

    for (int i = 1; i < n; i++) {
        char *p = trim(t[i]);
        struct TreeNode *cur = NULL;
        if (*p != 'n') {
            cur = make_tree_node(atoi(p));
        }
        // 将当前节点挂到前面第一个节点上，左或右
        struct TreeNode* pre = ret[top];
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
