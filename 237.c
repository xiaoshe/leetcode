#include <stdio.h>
#include <limits.h>
#include "util.h"

// 复制下一个节点内容，删除下一个节点
void deleteNode(struct ListNode* node) {
    struct ListNode* next = node->next;
    node->val = next->val;
    node->next = next->next;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct ListNode *h = init(a, n);
    print_list(h);

    deleteNode(h->next);
    print_list(h);
}
