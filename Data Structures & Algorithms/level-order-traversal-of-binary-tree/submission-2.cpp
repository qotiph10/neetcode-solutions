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

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            vector<int> lvl;
            for(int i = q.size() ;i >0 ;i--){
                TreeNode *temp = q.front();
                q.pop();
                if(temp){
                    lvl.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            if(lvl.size()){
                ans.push_back(lvl);
            }
        }  
        return ans;
    }
};
