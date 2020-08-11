#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "util.h"
#include "util.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;

        vector<TreeNode*> stack;
        if (root != NULL) stack.push_back(root);
        // 增加一个bool变量，代表从左到右或从右到左
        bool from_left_to_right = true;
        while (!stack.empty()) {
            // 记录某一层结果
            vector<int> val;
            val.reserve(stack.size());
            // 记录下一层的节点
            vector<TreeNode*> next;
            for (size_t i = 0; i < stack.size(); i++) {
                if (from_left_to_right) {
                    val.push_back(stack[i]->val);
                } else {
                    val.insert(val.begin(), stack[i]->val);
                }
                if (stack[i]->left != NULL) next.push_back(stack[i]->left);
                if (stack[i]->right != NULL) next.push_back(stack[i]->right);
            }
            ret.push_back(val);
            stack = next;
            from_left_to_right = !from_left_to_right;
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
    vector<vector<int> > ret = s.zigzagLevelOrder(left);
    for (size_t i = 0; i < ret.size(); i++) {
        print_vector(ret[i]);
    }

}
