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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int qSize;
        TreeNode *qTop;
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;

        q.push(root);

        while(!q.empty()){
            qSize = q.size();
            vector<int> levelNodes;
            for(int i=0;i<qSize;i++){
                qTop = q.front();
                q.pop();
                levelNodes.push_back(qTop->val);
                if(qTop->left)
                    q.push(qTop->left);
                if(qTop->right)
                    q.push(qTop->right);
            }
            ans.push_back(levelNodes);
        }
        return ans;
    }
};
