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
    void helper(TreeNode *root, int &ans, int maxTillNow){
        if(!root) return;
        if(root->val >= maxTillNow)
            ans++;
        maxTillNow = max(maxTillNow, root->val);
        helper(root->left, ans, maxTillNow);
        helper(root->right, ans, maxTillNow);
        
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        helper(root, ans, -101);
        return ans;
    }
};
