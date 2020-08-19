#include "util.h"
#include "util.hpp"

class Solution {
public:
    /*
    // 方法1
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;

        list<TreeNode*> tmp;
        tmp.push_back(root);
        // 循环push左子树，直到没有为止
        // pop后将数字输出
        // push右子树一次
        bool push = true;
        TreeNode *last = root;
        while (!tmp.empty()) {
            while (push && last->left != NULL) {
                tmp.push_back(last->left);
                last = last->left;
                push = true;
            }
            last = tmp.back();
            tmp.pop_back();
            push = false;

            ret.push_back(last->val);
            if (last->right != NULL) {
                tmp.push_back(last->right);
                last = last->right;
                push = true;
            }
        }
        return ret;
    }
    */
    // 方法2
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        list<TreeNode*> tmp;
        TreeNode *p = root;
        while (p) {
            tmp.push_back(p);
            p = p->left;
        }
        while (!tmp.empty()) {
            p = tmp.back();
            tmp.pop_back();
            ret.push_back(p->val);
            p = p->right;
            while (p) {
                tmp.push_back(p);
                p = p->left;
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct TreeNode* left = init_tree(a, n);
    print_tree_middle(left);

    Solution s;
    vector<int> ret = s.inorderTraversal(left);
    PrintVector(ret);
    return 0;
}
