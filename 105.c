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
    char *file = "data/105.txt";
    FILE *rp = fopen(file, "r");
    char s[128];
    while (fgets(s, 128, rp)) {
        if (s[0] == '#') continue;
        char *p = s;
        while (*p != ' ') p++;
        *p = 0;

        int left[32];
        int leftsz = string_to_array(s, left);
        print_array(left, leftsz);

        int right[32];
        int rightsz = string_to_array(p+1, right);
        print_array(right, rightsz);


        // TODO
        
        struct TreeNode* root = buildTree(left, leftsz, right, rightsz);
        print_tree_middle(root);
        
    }
    fclose(rp);
    return 0;
}
