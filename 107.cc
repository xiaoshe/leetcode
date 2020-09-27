#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "util.h"
#include "util.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        vector<TreeNode*> stack;
        if (root != NULL) stack.push_back(root);
        while (!stack.empty()) {
            vector<int> t;
            t.reserve(stack.size());

            vector<TreeNode*> new_stack;
            new_stack.reserve(stack.size() * 2);
            for (size_t i = 0; i < stack.size(); i++) {
                TreeNode* n = stack[i];
                t.push_back(n->val);
                if (n->left != NULL) {
                    new_stack.push_back(n->left);
                }
                if (n->right != NULL) {
                    new_stack.push_back(n->right);
                }
            }
            ret.insert(ret.begin(), t);
            stack = new_stack;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    // 3,9,20,null,null,15,7
    TreeNode *root = make_tree_node(3);
    root->left = make_tree_node(9);
    TreeNode *right = make_tree_node(20);
    root->right = right;
    right->left = make_tree_node(15);
    right->right = make_tree_node(7);

    print_tree_middle(root);
    printf("\n");



    Solution s;
    vector<vector<int> > ret = s.levelOrderBottom(root);
    for (size_t i = 0; i < ret.size(); i++) {
        print(ret[i]);
    }

}
