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

// 方法1：分治，（1）递归，（2）两两合并
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0) return NULL;
    while (listsSize > 1) {
        int half = listsSize / 2;
        for (int i = 0; i < half; i++) {
            lists[i] = merge(lists[i], lists[listsSize - i - 1]);
        }
        if (listsSize % 2 == 0) {
            listsSize = half;
        } else {
            listsSize = half + 1;
        }
    }
    return lists[0];
}

int main(int argc, char *argv[]) {
    struct ListNode *lists[32];
    int sz = 0;
    FILE *rp = fopen("23.txt", "r");
    char str[128];
    while (fgets(str, 128, rp)) {
        int a[32];
        int n = string_to_array(str, a);
        struct ListNode *l = init(a, n);
        lists[sz++] = l;
        printf("%s\n", str);
        print_list(l);
    }
    fclose(rp);

    struct ListNode *ret = mergeKLists(lists, sz);
    print_list(ret);

    return 0;
}
