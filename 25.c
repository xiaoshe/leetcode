#include "util.h"

struct Pair {
    struct ListNode *head;
    struct ListNode *tail;
};

// 将head分割成2个链表head和out（记录head,tail）
struct ListNode *split(struct ListNode *head, int k, struct Pair *out) {
    struct ListNode *p = head;
    while (k > 0) {
        k--;
        struct ListNode *nxt = p->next;
        if (out->head == NULL) {
            p->next = NULL;
            out->head = p;
            out->tail = p;
        } else {
            p->next = out->head;
            out->head = p;
        }
        p = nxt;
    }
    return p;
}

// b追加到a后面
struct Pair merge(struct Pair a, struct Pair b) {
    if (a.head == NULL) return b;
    a.tail->next = b.head;
    a.tail = b.tail;
    return a;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int len = 0;
    struct ListNode *p = head;
    while (p) {
        len++;
        p = p->next;
    }

    struct Pair ret = {NULL, NULL};
    while (len >= k) {
        // 当剩余长度大于k时，切分链表
        struct Pair tmp = {NULL, NULL};
        head = split(head, k, &tmp);
        // 合并反转的部分
        ret = merge(ret, tmp);
        len -= k;
    }
    if (len > 0) {
        ret.tail->next = head;
    }
    return ret.head;
}


int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct ListNode *ret = init(a, n);
    print_list(ret);

    struct ListNode *r = reverseKGroup(ret, atoi(argv[2]));
    print_list(r);
    return 0;
}
