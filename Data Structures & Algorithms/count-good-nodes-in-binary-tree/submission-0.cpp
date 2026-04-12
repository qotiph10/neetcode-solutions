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
    int count = 0; 
public:
    int goodNodes(TreeNode* root) {
        dfs(root , INT_MIN);
        return count;
    }
    void dfs(TreeNode* root ,int max){
        if(!root){
            return;
        }
        if(root->val >= max){
            max = root->val;
            count+=1;
        }
        dfs(root->right , max);
        dfs(root->left , max);
    }
};
