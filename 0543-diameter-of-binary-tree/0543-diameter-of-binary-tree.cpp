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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        findDia(root, dia);
        return dia;
    }

    int findDia(TreeNode* root, int &dia) {
        if(!root) return 0;

        int lh = findDia(root->left, dia);
        int rh = findDia(root->right, dia);
        
        dia = max(dia, lh + rh);

        return 1 + max(lh, rh);
    }
};