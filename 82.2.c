#include "util.h"

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* next = head->next;

    // 开头重复
    if (head->val == next->val) {
        while (next && next->val == head->val) next = next->next;
        head = deleteDuplicates(next);
    } else {
        head->next = deleteDuplicates(next);
    }
    return head;
}

int main(int argc, char *argv[]) {
    struct ListNode* head = init_list(argv[1]);
    struct ListNode* ret = deleteDuplicates(head);
    print_list(ret);
    return 0;
}
