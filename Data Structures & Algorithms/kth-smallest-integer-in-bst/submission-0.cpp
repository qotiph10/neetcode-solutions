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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vals;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            for(int i = q.size() -1;i >= 0 ;i--){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    q.push(node->left);
                    q.push(node->right);
                    vals.push_back(node->val);
                }
            }
        }
        sort(vals.begin() , vals.end());
        return vals[k-1];
    }
};
