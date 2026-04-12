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
    int count(TreeNode* root , int maxVal){
        if(!root){
            return 0;
        }

        if(root->val >= maxVal){
            cout << root->val << " new Max " << endl;
            return 1 + count(root->right , root->val) + count(root->left , root->val);
        }
        else{
            cout << root->val << " no change " << endl;
            return count(root->right , maxVal) + count(root->left , maxVal);
        }
    }
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }

        return count(root , INT_MIN);
    }
};
