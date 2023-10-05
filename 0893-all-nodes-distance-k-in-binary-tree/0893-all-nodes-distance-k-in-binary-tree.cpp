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
    void findParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentPointer) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            if(top->left) {
                parentPointer[top->left] = top;
                q.push(top->left);
            }

            if(top->right) {
                parentPointer[top->right] = top;
                q.push(top->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentPointer;
        findParents(root, parentPointer);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);

        visited[target] = true;
        int curr_level = 0;

        while(!q.empty()) {
            int size = q.size();
            if(curr_level == k) break;
            curr_level++;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parentPointer[node] && !visited[parentPointer[node]]) {
                    q.push(parentPointer[node]);
                    visited[parentPointer[node]] = true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};