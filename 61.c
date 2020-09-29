#include "util.h"


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL) return NULL;
    int n = 0;
    struct ListNode *p = head;
    while (p) {
        n++;
        p = p->next;
    }
    k = k % n;
    if (n < 2 || k == 0) return head;
    
    int end = n - k - 1;
    // 移到最后一个节点
    struct ListNode *endp = head;
    while (end-- > 0) {
        endp = endp->next;
    }
    // 下一节点即为头节点
    struct ListNode *ret = endp->next;
    endp->next = NULL; // 断开
    p = ret;
    while (p->next) p = p->next;
    p->next = head;
    return ret;
}

int main(int argc, char *argv[]) {
    char *s = "1,2,3,4,5";
    int k = 2;

    s = "0,1,2";
    k = 0;

    /*
    s = "1";
    k = 2;
    */

    struct ListNode* l = init_list(s);
    print_list(l);

    struct ListNode* ret = rotateRight(l, k);
    print_list(ret);

    return 0;
}
