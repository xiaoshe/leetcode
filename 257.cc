#include "util.h"
#include "util.hpp"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == NULL) return ret;

        list<string> l;
        paths("", root, &l);
        ret.assign(l.begin(), l.end());
        return ret;
    }

    void paths(const string& s, TreeNode *node, list<string> *ret) const {
        string out;
        out.reserve(s.size() + 16);
        out = s;
        char t[16];
        if (out.empty()) {
            sprintf(t, "%d", node->val);
            out.assign(t);
        } else {
            sprintf(t, "->%d", node->val);
            out.append(t);
        }
        if (node->left == NULL && node->right == NULL) {
            // 叶子节点
            ret->push_back(out);
            return;
        }
        if (node->left != NULL) {
            paths(out, node->left, ret);
        }
        if (node->right != NULL) {
            paths(out, node->right, ret);
        }
    }
};

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    struct TreeNode* left = init_tree(a, n);
    print_tree_middle(left);

    Solution s;
    vector<string> ret = s.binaryTreePaths(left);
    print(ret);
    return 0;
}
