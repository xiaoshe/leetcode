#include <stdio.h>
#include <limits.h>
#include "util.h"

// 要求：扫描一遍
// 思路：重新构建一个单链表
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (head == NULL) return NULL;
    struct ListNode *ret = NULL;
    struct ListNode *tail = NULL;
    struct ListNode *prev = NULL;// 指向m-1个节点
    struct ListNode *p = head;
    int c = 1;
    while (p != NULL) {
        struct ListNode *nxt = p->next;
        p->next = NULL;

        if (c <= m || c > n) {
            // 插入尾部
            if (ret == NULL) {
                ret = p;
                tail = p;
            } else {
                prev = tail;
                tail->next = p;
                tail = p;
            }
        } else {
            if (prev == NULL) {
                p->next = ret;
                ret = p;
            } else {
                p->next = prev->next;
                prev->next = p;
            }
        }
        p = nxt;
        c++;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    struct ListNode *ret = init_list(argv[1]);
    print_list(ret);

    struct ListNode *r = reverseBetween(ret, atoi(argv[2]), atoi(argv[3]));
    print_list(r);

    return 0;
}
