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

class BSTIterator {
private:
    stack<TreeNode*> myStack;
    bool reverse = true;

public:
    BSTIterator(TreeNode* node, bool isReverse) {
        reverse = isReverse;
        pushAll(node);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode* node = myStack.top();
        myStack.pop();

        if(!reverse) pushAll(node->right);
        else pushAll(node->left);

        return node->val;
    }

private:
    void pushAll(TreeNode* node) {
        while(node) {
            myStack.push(node);
            if(reverse) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j) {
            if(i + j == k) return true;
            else if(i + j < k) {
                i = l.next();
            } else {
                j = r.next();
            }
        }

        return false;
    }
};