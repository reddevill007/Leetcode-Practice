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
private:
    int findMaxPath(TreeNode* node, int& ans) {
        if(!node) return 0;

        int leftSum = max(0, findMaxPath(node->left, ans));
        int rightSum = max(0, findMaxPath(node->right, ans));

        int current_max = node->val + leftSum + rightSum;

        ans = max(ans, current_max);

        return node->val + max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findMaxPath(root, ans);
        return ans;
    }
};