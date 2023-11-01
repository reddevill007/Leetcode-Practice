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
    void getAnswer(TreeNode* root, unordered_map<int, int> &mp) {
        if(!root) return;

        getAnswer(root->left, mp);
        mp[root->val]++;
        getAnswer(root->right, mp);
    }

public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int> ans;

        getAnswer(root, mp);
        int maxFreq = 0;

        for(auto it: mp) {
            if(it.second > maxFreq) maxFreq = it.second;
        }

        for(auto it: mp) {
            if(it.second == maxFreq) ans.push_back(it.first);
        }

        return ans;
    }
};