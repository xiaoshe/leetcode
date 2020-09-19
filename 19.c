#include "util.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // 使用前后2个指针：first，second
    // first先移动n+1个位置，然后同时移动，删除second->next节点
    // 注意：删除第一个节点的判断
    struct ListNode *first = head;
    int m = 0;
    while (first != NULL && m != n + 1) {
        first = first->next;
        m++;
    }
    if (m != n + 1) {
        // 删除头节点
        return head->next;
    }
    struct ListNode *second = head;
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return head;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct ListNode *ret = init_list(a, n);
    print_list(ret);

    struct ListNode *r = removeNthFromEnd(ret, atoi(argv[2]));
    print_list(r);
    return 0;
}
