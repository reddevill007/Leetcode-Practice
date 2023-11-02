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
    // pair<int, int> calculateSumCount(TreeNode* root, int currSum, int currCount) {  
    //     if(!root) return make_pair(currSum, currCount);

    //     currSum = currSum + root->val;
    //     currCount = currCount + 1;

    //     pair<int, int>  leftSum = calculateSumCount(root->left, currSum, currCount);
    //     pair<int, int>  rightSum = calculateSumCount(root->right, currSum, currCount);

    //     return make_pair(leftSum.first + rightSum.first - root->val, leftSum.second + rightSum.second - 1);
    // }

    int calculateSumCount(TreeNode* node, int &count) {
        if(!node) return 0;
        count++;

        int lSum = calculateSumCount(node->left, count);
        int rSum = calculateSumCount(node->right, count);

        return node->val + lSum + rSum;
    }

    void checkAvg(TreeNode* root, int &ans) {
        // if(!root) return;

        // pair<int, int> currSol = calculateSumCount(root, 0, 0);
        // int nodeAvg = currSol.first / currSol.second;
        // int nodeVal = root->val;
        // if(nodeVal == nodeAvg) ans += 1;
        // checkAvg(root->left, ans);
        // checkAvg(root->right, ans);

        if(!root) return;

        int count = 0;
        int sum = calculateSumCount(root, count);
        int avg = sum / count;

        if(root-> val == avg) ans++;
        
        checkAvg(root->left, ans);
        checkAvg(root->right, ans);
    }

public:
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        checkAvg(root, ans);
        return ans;
    }
};