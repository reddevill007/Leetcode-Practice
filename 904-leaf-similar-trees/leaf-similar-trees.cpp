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
    void getLeafValues(TreeNode* root, vector<int> &nodeList_root) {
        if(!root) return;

        if(!root->left && !root->right) {
            nodeList_root.push_back(root->val);
            return;
        }

        getLeafValues(root->left, nodeList_root);
        getLeafValues(root->right, nodeList_root);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nodeList_root1, nodeList_root2;

        getLeafValues(root1, nodeList_root1);
        getLeafValues(root2, nodeList_root2);

        return nodeList_root1 == nodeList_root2;
    }
};