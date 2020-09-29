#include <stdio.h>
#include <limits.h>
#include "util.h"

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(int argc, char *argv[]) {
    struct ListNode *h = init_list(argv[1]);
    print_list(h);

    struct ListNode *ret = middleNode(h);
    print_list(ret);
}
