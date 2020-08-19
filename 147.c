#include <stdio.h>
#include <limits.h>
#include "util.h"

struct ListNode *insert(struct ListNode *head, struct ListNode *p) {
    // 注意相同的数字
    // 插入位置有3种：前中后
    if (head->val >= p->val) {
        // 前
        p->next = head;
        return p;
    }
    struct ListNode *prev = head;
    struct ListNode *next = prev->next;
    while (next != NULL) {
        if (prev->val < p->val && p->val <= next->val) {
            // 中
            prev->next = p;
            p->next = next;
            break;
        }
        prev = next;
        next = next->next;
    }
    // 后
    prev->next = p;
    // 中和后返回head
    return head;
}

struct ListNode* insertionSortList(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode *p = head->next;
    head->next = NULL;
    while (p != NULL) {
        struct ListNode *next = p->next;
        // 将p节点插入到head链表中
        p->next = NULL;
        head = insert(head, p);
        p = next;
    }
    return head;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct ListNode *ret = init(a, n);
    print_list(ret);

    struct ListNode *r = insertionSortList(ret);
    print_list(r);

    return 0;
}
