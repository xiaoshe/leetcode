#include <stdio.h>
#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *make(int v) {
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = v;
    p->next = NULL;
    return p;
}

#define append(ret, tail, p) \
    if (ret == NULL) { \
        ret = p; \
        tail = p; \
	} else { \
        tail->next = p; \
        tail = p; \
    }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *ret = NULL;
    struct ListNode *tail = NULL;

    int flag = 0; // 进位
    while (p1 != NULL && p2 != NULL) {
        // 2个链表同时顺序扫描
        int sum = p1->val + p2->val + flag;
        flag = sum / 10;
        struct ListNode *p = make(sum % 10);
		append(ret, tail, p);
        p1 = p1->next;
        p2 = p2->next;
    }

    // 扫描剩余链表
    struct ListNode *left = (p1 != NULL) ? p1 : p2;
    while (left != NULL) {
        int sum = left->val + flag;
        flag = sum / 10;
        struct ListNode *p = make(sum % 10);
		append(ret, tail, p);
        left = left->next;
    }
    // 如果进位
    if (flag > 0) {
        struct ListNode *p = make(flag);
		append(ret, tail, p);
    }
    if (ret == NULL) {
        ret = make(0);
    }
    
    return ret;
}

int main(int argc, char *argv[]) {
	struct ListNode *h11 = make(2);
	struct ListNode *h12 = make(4);
	struct ListNode *h13 = make(3);
	h11->next = h12;
	h12->next = h13;

	struct ListNode *h21 = make(5);
	struct ListNode *h22 = make(6);
	struct ListNode *h23 = make(4);
	h21->next = h22;
	h22->next = h23;

	struct ListNode * ret = addTwoNumbers(h11, h21);
	while (ret != NULL) {
		printf("%d ", ret->val);
		ret = ret->next;
	}
	printf("\n");
}
