/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, int& count, vector<int> &count_num) {
        if (!root)
            return;

        count_num[root->val]++;
        solve(root->left, count, count_num);
        solve(root->right, count, count_num);
        if (!root->left && !root->right) {
            int num_of_odd_occ = 0;

            for(int i = 1; i <= 9; i++) {
                if(count_num[i] % 2 != 0) num_of_odd_occ++;
            }

            if(num_of_odd_occ <= 1) count++;
        }

        count_num[root->val]--;
    }

public:
    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;
        vector<int> count_num(10, 0);
        solve(root, count, count_num);
        return count;
    }
};