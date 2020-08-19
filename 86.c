#include <stdio.h>
#include <limits.h>
#include "util.h"


/*
// 链表拆了重新组装
// 小的插入头，大的插入尾
// 输入：[1,4,3,2,5,2] 3，输出：[2,2,1,4,3,5]，与期望值[1,2,2,4,3,5]不符合，shit
//
struct ListNode* partition(struct ListNode* head, int x){
    if (head == NULL) return NULL;
    struct ListNode *h = head;
    struct ListNode *t = head;
    struct ListNode *p = head->next;
    while (p != NULL) {
        // 记录p的下一个节点
        struct ListNode* n = p->next;
        p->next = NULL;
        if (p->val < x) {
            // 头部插入
            p->next = h;
            h = p;
        } else {
            // 尾部插入
            t->next = p;
            t = p;
        }
        p = n;
    }
    return h;
}
*/

// 链表拆了创建2个链表，最后合并
struct ListNode* partition(struct ListNode* head, int x){
    if (head == NULL) return NULL;
    struct ListNode *left = NULL;
    struct ListNode *left_tail = NULL;
    struct ListNode *right = NULL;
    struct ListNode *right_tail = NULL;

    struct ListNode *p = head;
    while (p != NULL) {
        // 记录p的下一个节点
        struct ListNode* n = p->next;
        p->next = NULL;
        if (p->val < x) {
            // 插入left列表尾部
            if (left == NULL) {
                left = p;
                left_tail = p;
            } else {
                left_tail->next = p;
                left_tail = p;
            }
        } else {
            // 插入right列表尾部
            if (right == NULL) {
                right = p;
                right_tail = p;
            } else {
                right_tail->next = p;
                right_tail = p;
            }
        }
        p = n;
    }

    if (left == NULL) return right;
    left_tail->next = right;
    return left;
}


int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct ListNode *ret = init(a, n);
    print_list(ret);

    struct ListNode *r = partition(ret, atoi(argv[2]));
    print_list(r);

    return 0;
}
