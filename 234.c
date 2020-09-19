#include <stdio.h>
#include <limits.h>
#include "util.h"

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode *ret = head;
    head = head->next;
    ret->next = NULL;
    while (head != NULL) {
        struct ListNode *p = head;
        struct ListNode *next = head->next;
        head = next;
        
        p->next = ret;
        ret = p;
    }
    return ret;
}

int isPalindrome(struct ListNode* head){
    // 链表长度
    int len = 0;
    struct ListNode *p = head;
    while (p != NULL) {
        ++len;
        p = p->next;
    }

    // 移动到链表中间，如果是奇数，跳过最中间那个节点
    int count = len / 2;
    if (len % 2 == 1) count += 1;
    struct ListNode *middle = head;
    while (count-- > 0) {
        middle = middle->next;
    }

    // 反转后面单链表
    struct ListNode *q = reverseList(middle);	
    p = head;

    // 判断后半部分与前面一致
    while (q != NULL) {
        if (q->val != p->val) return 0;
        q = q->next;
        p = p->next;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct ListNode *h = init_list(a, n);
    print_list(h);

    int ret = isPalindrome(h);
    printf("ret:%d\n", ret);
}
