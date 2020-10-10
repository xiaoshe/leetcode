#include "util.h"

struct ListNode* deleteHeadDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    int v = head->val;
    struct ListNode *p = head->next;
    if (v != p->val) return head;

    while (p != NULL) {
        if (p->val != v) return p;
        p = p->next;
    }
    return NULL;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *ret = NULL;
    struct ListNode *tail = NULL;
    struct ListNode* p = head;
    while (1) {
        p = deleteHeadDuplicates(p);
        // 依旧存在重复
        if (p && p->next && p->val == p->next->val) continue;
        if (p == NULL) break;
        struct ListNode* n = p->next;
        p->next = NULL;
        // 追加节点p
        if (ret == NULL) {
            ret = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
        p = n;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    struct ListNode* head = init_list(argv[1]);
    struct ListNode* ret = deleteDuplicates(head);
    print_list(ret);
    return 0;
}
