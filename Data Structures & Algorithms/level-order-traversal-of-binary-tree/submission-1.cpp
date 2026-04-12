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
        if(!root){
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> lvl;
            for(int i = q.size() -1 ;i >= 0 ;i--){
                TreeNode *node = q.front();
                q.pop();
                if(node){
                    lvl.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(lvl.size()){
                ans.push_back(lvl);
            }
        }
        return ans;
    }
};
