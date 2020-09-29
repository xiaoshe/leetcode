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
    struct ListNode *h = init_list(argv[1]);
    print_list(h);

    deleteNode(h->next);
    print_list(h);
}
