#include "util.h"


int get_size(struct ListNode* head) {
    int sz = 0;
    struct ListNode* p = head;
    while (p) {
        sz++;
        p = p->next;
    }
    return sz;
}

// 分成2段，前k个节点为第一段，返回后段头节点
struct ListNode* split_list(struct ListNode* head, int k) {
    if (head == NULL || k == 0) return head;
    struct ListNode* p = head;
    while (--k > 0) {
        p = p->next;
    }
    struct ListNode* ret = p->next;
    p->next = NULL;
    return ret;
}

struct ListNode* reverse_list(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode *ret = head;
    head = head->next;
    ret->next = NULL;
    while (head != NULL) {
        struct ListNode *p = head;
        struct ListNode *next = head->next;
        head = next;
        
        p->next = ret;
        ret = p;
    }
    return ret;
}

struct ListNode* merge_list(struct ListNode* left, struct ListNode* right) {
    if (left == NULL) return NULL;
    struct ListNode* ret = left;
    struct ListNode* tail = left;
    left = left->next;

    while (right && left) {
        struct ListNode* right_next = right->next;
        struct ListNode* left_next = left->next;
        tail->next = right;
        tail = right;
        tail->next = left;
        tail = left;
        tail->next = NULL;

        right = right_next;
        left = left_next;
    }
    if (right) tail->next = right;
    if (left) tail->next = left;
    return ret;
}

void reorderList(struct ListNode* head){
    int size = get_size(head);
    if (size < 3) return;
    struct ListNode* right = reverse_list(split_list(head, size/2));
    merge_list(head, right);
}

int main(int argc, char *argv[]) {
    char *s = "1,2,3,4,5";
    struct ListNode* head = init_list(s);
    print_list(head);
    reorderList(head);
    print_list(head);
    return 0;
}
