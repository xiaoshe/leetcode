#include "util.hpp"

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector< vector<int> > ret;
        if (root == NULL) return ret;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> t;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                Node* n = q.front();
                q.pop();
                t.push_back(n->val);
                for (int j = 0; j < n->children.size(); j++) {
                    q.push(n->children[j]);
                }
            }
            ret.push_back(t);
        }
        return ret;
    }
};
int main(int argc, char *argv[]) {
    return 0;
}
