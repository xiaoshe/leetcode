#include "util.h"

struct ListNode* merge(struct ListNode *left, struct ListNode *right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct ListNode *l = left;
    struct ListNode *r = right;

    struct ListNode *ret = NULL;
    struct ListNode *tail = NULL;
    if (l->val < r->val) {
        ret = l;
        tail = l;
        l = l->next;
    } else {
        ret = r;
        tail = r;
        r = r->next;
    }
    while (l && r) {
    }
    return ret;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

}

int main(int argc, char *argv[]) {
    return 0;
}
