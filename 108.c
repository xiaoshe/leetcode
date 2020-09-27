#include "util.h"

struct TreeNode *bstree(int *nums, int l, int r) {
    if (l > r) return NULL;
    int mid = (l + r)/2;
    struct TreeNode *ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    ret->val = nums[mid];
    ret->left = bstree(nums, l, mid-1);
    ret->right = bstree(nums, mid+1, r);
    return ret;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return bstree(nums, 0, numsSize-1);
}


int main(int argc, char *argv[]) {
    char *file = "data/108.txt";
    FILE *rp = fopen(file, "r");
    char s[128];
    while (fgets(s, 128, rp)) {
        if (s[0] == '#') continue;
        int a[32];
        int n = string_to_array(s, a);
        print_array(a, n);

        // TODO
        struct TreeNode *root = sortedArrayToBST(a, n);
        print_tree(root);
        
    }
    fclose(rp);
    return 0;
}
