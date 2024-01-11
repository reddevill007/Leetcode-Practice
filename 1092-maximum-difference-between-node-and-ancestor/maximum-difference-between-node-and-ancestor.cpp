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
    int helper(TreeNode* node, int currMax, int currMin) {
        if(!node) return currMax - currMin;

        currMax = max(node->val, currMax);
        currMin = min(node->val, currMin);

        int l = helper(node->left, currMax, currMin);
        int r = helper(node->right, currMax, currMin);

        return max(l, r);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        return helper(root, root->val, root->val);
    }
};