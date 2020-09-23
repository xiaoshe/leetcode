#include "../util.h"

struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if (head == NULL) return NULL;
    int f[20001] = {0};
    struct ListNode *p = head->next;
    struct ListNode *ret = head;
    f[ret->val] = 1;
    struct ListNode *tail = head;
    tail->next = NULL;
    while (p != NULL) {
        if (f[p->val] == 0) {
            tail->next = p;
            tail = p;
            f[p->val] = 1;
            p = p->next;
            tail->next = NULL;
        } else {
            p = p->next;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int a[32] = {1, 2, 3, 3, 2, 1};
    struct ListNode *l = init_list(a, 6);
    struct ListNode *l2 = removeDuplicateNodes(l);
    print_list(l2);
    return 0;
}
