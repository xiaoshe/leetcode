#include "util.h"

// 合并2个有序单链表
struct ListNode* merge(struct ListNode *left, struct ListNode *right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct ListNode *l = left;
    struct ListNode *r = right;

    struct ListNode *ret = NULL;
    struct ListNode *tail = NULL;
    // 第一个节点
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
        if (l->val < r->val) {
            // 插入l节点
            tail->next = l;
            tail = l;
            l = l->next;
        } else {
            tail->next = r;
            tail = r;
            r = r->next;
        }
    }
    if (l) tail->next = l;
    if (r) tail->next = r;
    return ret;
}

struct ListNode* go(struct ListNode* head, int size) {
    if (size == 0) return NULL;
    if (size == 1) return head;
    int mid = size / 2;
    struct ListNode *p = head;
    for (int i = 0; i < mid - 1; i++) {
        p = p->next;
    }
    struct ListNode* midnode = p->next;
    p->next = NULL; // 断开链接，否则merge时报错
    struct ListNode* left = go(head, mid);
    struct ListNode* right = go(midnode, size - mid);
    return merge(left, right);
}

struct ListNode* sortList(struct ListNode* head){
    struct ListNode *p = head;
    int size = 0;
    while (p) {
        size++;
        p = p->next;
    }
    return go(head, size);
}

int main(int argc, char *argv[]) {
    char *file = "data/148.txt";
    FILE *rp = fopen(file, "r");
    char s[128];
    while (fgets(s, 128, rp)) {
        if (s[0] == '#') continue;

        // TODO
        struct ListNode *l = init_list(s);
        print_list(l);
        l = sortList(l);
        print_list(l);
        

        
    }
    fclose(rp);
    return 0;
}
