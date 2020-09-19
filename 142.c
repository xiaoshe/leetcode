#include "util.h"

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) return NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (slow != fast) {
        printf("slow:%d fast:%d\n", slow->val, fast->val);
        slow = slow->next;
        fast = fast->next;
        if (fast == NULL) return NULL;
        fast = fast->next;
    }
    return slow;
}

int main(int argc, char *argv[]) {
    int a[32];
    char *s = "3,2,0,-4";
    int n = string_to_array(s, a);
    print_array(a, n);
    struct ListNode *list = init_list(a, n);
    print_list(list);
    struct ListNode *tail = tail_list(list);
    tail->next = list->next;

    struct ListNode *ret = detectCycle(list);
    if (ret == NULL) printf("NULL\n");
    else printf("ret:%d\n", ret->val);

    return 0;
}
