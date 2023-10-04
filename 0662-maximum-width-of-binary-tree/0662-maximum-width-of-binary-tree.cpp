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
    int widthOfBinaryTree(TreeNode* root) {
       if(!root) return 0;

       queue<pair<TreeNode*, long long>> todo;
       todo.push({root, 0});

       long long ans = 0;

       while(!todo.empty()) {
           int size = todo.size();
           int mmin = todo.front().second;

           long long first, last;
            for(int i = 0; i < size; i++) {
                long long curr_ind = todo.front().second - mmin;
                TreeNode* node = todo.front().first;
                todo.pop();

                if(i == 0) first = curr_ind;
                if(i == size - 1) last = curr_ind;

                if(node->left) {
                    todo.push({
                        node->left,
                        curr_ind * 2 + 1
                    });
                }

                if(node->right) {
                    todo.push({
                        node->right,
                        curr_ind * 2 + 2
                    });
                }
            }

            ans = max(ans, last - first + 1);
       }

       return (int)ans;
    }
};