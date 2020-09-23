#include "../util.h"

int kthToLast(struct ListNode* head, int k){
    struct ListNode* p1 = head;
    while (k > 0) {
        p1 = p1->next;
        k--;
    }
    struct ListNode* p2 = head;
    while (p1 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2->val;
}

int main(int argc, char *argv[]) {
    int a[32] = {1,2,3,4,5};
    int k = 2;
    struct ListNode *l = init_list(a, 5);
    int ret = kthToLast(l, 2);
    printf("ret:%d\n", ret);
    return 0;
}
