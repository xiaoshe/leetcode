#include "util.h"

// [pstart, pend], [istart, iend]
struct TreeNode* go(int *preorder, int pstart, int pend, int *inorder, int istart, int iend) {
    if (pstart > pend) return NULL;
    struct TreeNode* ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int key = preorder[pstart];
    int pos = istart;
    while (pos <= iend) {
        if (inorder[pos] == key) break;
        pos++;
    }
    ret->val = key;
    ret->left = go(preorder, pstart+1, pstart+pos-istart, inorder, istart, pos-1);
    ret->right = go(preorder, pstart+pos-istart+1, pend, inorder, pos+1, iend);
    return ret;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return go(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}

int main(int argc, char *argv[]) {
    int left[32] = {3,9,20,15,7};
    int leftsz = 5;
    int right[32] = {9,3,15,20,7};
    int rightsz = 5;
        
    struct TreeNode* root = buildTree(left, leftsz, right, rightsz);
    print_tree(root);
        
    return 0;
}
