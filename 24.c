#include <stdio.h>
#include <limits.h>
#include "util.h"


// 递归调用
struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    // 交换head和next
    struct ListNode *next = head->next;
    struct ListNode *next2 = next->next;
    next->next = head;
    head->next = swapPairs(next2);
    return next;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct ListNode *ret = init_list(a, n);
    print_list(ret);

    struct ListNode *r = swapPairs(ret);
    print_list(r);

    return 0;
}
