#include "util.h"

struct TreeNode *bstree(struct ListNode* head, int size) {
    if (size == 0) return NULL;
    int mid = size / 2;
    struct ListNode *p = head;
    for (int i = 0; i < mid; i++) p = p->next;
    struct TreeNode *ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    ret->val = p->val;
    ret->left = bstree(head, mid);
    ret->right = bstree(p->next, size - mid - 1);
    return ret;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    int size = 0;
    struct ListNode *p = head;
    while (p != NULL) {
        size++;
        p = p->next;
    }

    return bstree(head, size);
}


int main(int argc, char *argv[]) {
    char *file = "data/108.txt";
    FILE *rp = fopen(file, "r");
    char s[128];
    while (fgets(s, 128, rp)) {
        if (s[0] == '#') continue;
        int a[32];
        int n = string_to_array(s, a);
        struct ListNode *l = init_list(a, n);
        print_list(l);

        // TODO
        struct TreeNode *root = sortedListToBST(l);
        print_tree_middle(root);
        
    }
    fclose(rp);
    return 0;
}
