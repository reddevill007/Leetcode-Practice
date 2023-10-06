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
    void helper(TreeNode* root, int &count) {
        if(!root) return;
        helper(root->left, count);
        count++;
        helper(root->right, count);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int count = 0;
        helper(root, count);
        return count;
    }
};