#include "util.h"

/*
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) return NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
        if (fast == NULL) return NULL;
        fast = fast->next;
    }
    return slow;
}

// 不正经解法1：利用地址大小关系
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) return NULL;
    while (head) {
        if (head > head->next) return head->next;
        head = head->next;
    }
    return NULL;
}
*/
// 不正经解法2：遍历后修改val
struct ListNode *detectCycle(struct ListNode *head) {
    int v = 1000000;
    while (head) {
        if (head->val < -v || head->val > v) {
            return head;
        } else {
            head->val += head->val < 0 ? -v : v;
            head = head->next;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    char *s = "3,2,0,-4";
    struct ListNode *list = init_list(s);
    print_list(list);
    struct ListNode *tail = tail_list(list);
    tail->next = list->next;
    /*
    struct ListNode *list = init_list("1");
    print_list(list);
    */

    struct ListNode *ret = detectCycle(list);
    if (ret == NULL) printf("NULL\n");
    else printf("ret:%d\n", ret->val);

    return 0;
}
