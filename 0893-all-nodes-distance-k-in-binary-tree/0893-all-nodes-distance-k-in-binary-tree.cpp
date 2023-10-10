/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent) {
        queue<TreeNode*> todo;
        todo.push(root);

        while(!todo.empty()) {
            TreeNode* top = todo.front();
            todo.pop();

            if(top->left) {
                todo.push(top->left);
                parent[top->left] = top;
            }

            if(top->right) {
                todo.push(top->right);
                parent[top->right] = top;
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;

        markParents(root, parent);

        queue<TreeNode*> todo;
        todo.push(target);
        visited[target] = true;

        int curr_level = 0;

        while(!todo.empty()) {
            int size = todo.size();

            if(curr_level == k) break;
            curr_level++;

            for(int i = 0; i < size; i++) {
                TreeNode* top = todo.front();
                todo.pop();

                if(top->left && !visited[top->left]) {
                    todo.push(top->left);
                    visited[top->left] = true;
                }
                if(top->right && !visited[top->right]) {
                    todo.push(top->right);
                    visited[top->right] = true;
                }
                if(parent[top] && !visited[parent[top]]) {
                    todo.push(parent[top]);
                    visited[parent[top]] = true;
                }
            }
        }

        vector<int> ans;

        while(!todo.empty()) {
            TreeNode* top = todo.front();
            todo.pop();

            ans.push_back(top->val);
        }

        return ans;
    }
};