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
    TreeNode* findParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> & parent, int start, TreeNode* ref) {
        TreeNode* ans = NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }

            if(node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }

            if(node->val == start) ans = node;
        }

        return ans;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> node_map;
        unordered_map<TreeNode*, bool> visited;

        TreeNode* ref  = findParents(root, node_map, start, ref);

        queue<TreeNode*> todo;
        todo.push(ref);
        visited[ref] = true;

        int time = 0;

        while(!todo.empty()) {
            bool flag = false;
            
            cout << time;
            int size = todo.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = todo.front();
                todo.pop();

                if(node->left && !visited[node->left]) {
                    todo.push(node->left);
                    flag = true;
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]) {
                    todo.push(node->right);
                    flag = true;
                    visited[node->right] = true;
                }

                if(node_map[node] && !visited[node_map[node]]) {
                    todo.push(node_map[node]);
                    flag = true;
                    visited[node_map[node]] = true;
                }
            }

            if(flag) time++;
        }

        return time;
    }
};