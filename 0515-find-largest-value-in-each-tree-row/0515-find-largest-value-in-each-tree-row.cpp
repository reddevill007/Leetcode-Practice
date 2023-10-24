/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;

        queue<TreeNode*> todo;
        todo.push(root);

        while(!todo.empty()) {
            int size = todo.size();
            int max_el = INT_MIN;
            for(int i = 0; i < size; i++) {
                TreeNode* node = todo.front();
                todo.pop();

                max_el = max(max_el, node->val);

                if(node->left) todo.push(node->left);
                if(node->right) todo.push(node->right);
            }

            ans.push_back(max_el);
        }

        return ans;
    }
};