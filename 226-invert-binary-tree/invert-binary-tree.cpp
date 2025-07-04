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
   TreeNode* solve(TreeNode* root,TreeNode* ans){
    ans=new TreeNode(root->val);
    if(root->right){
        ans->left=solve(root->right,ans);
    }
    if(root->left){
        ans->right=solve(root->left,ans);
    }
    return ans;
   }
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)return root;
        TreeNode * ans;
        return solve(root,ans);

    }
};