#include "util.h"

// [pstart, pend], [istart, iend]
struct TreeNode* go(int *postorder, int pstart, int pend, int *inorder, int istart, int iend) {
    if (pstart > pend) return NULL;
    struct TreeNode* ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int key = postorder[pend];
    int pos = istart;
    while (pos <= iend) {
        if (inorder[pos] == key) break;
        pos++;
    }
    ret->val = key;
    ret->left = go(postorder, pstart, pstart+pos-istart-1, inorder, istart, pos-1);
    ret->right = go(postorder, pstart+pos-istart, pend-1, inorder, pos+1, iend);
    return ret;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return go(postorder, 0, postorderSize - 1, inorder, 0, inorderSize - 1);
}

int main(int argc, char *argv[]) {
    char *file = "data/106.txt";
    FILE *rp = fopen(file, "r");
    char s[128];
    while (fgets(s, 128, rp)) {
        if (s[0] == '#') continue;
        char *p = s;
        while (*p != ' ') p++;
        *p = 0;

        // postorder
        int left[32];
        int leftsz = string_to_array(s, left);
        print_array(left, leftsz);

        // inorder
        int right[32];
        int rightsz = string_to_array(p+1, right);
        print_array(right, rightsz);


        // TODO
        
        struct TreeNode* root = buildTree(right, rightsz, left, leftsz);
        print_tree(root);
        
    }
    fclose(rp);
    return 0;
}
