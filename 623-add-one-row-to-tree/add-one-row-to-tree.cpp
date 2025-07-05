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
   void  solve(TreeNode* root,int val,int idx,int &depth){
    if(root==nullptr)return;
    if(idx==depth-1){
        TreeNode* lefti=new TreeNode(val,root->left,nullptr);
        TreeNode* righti=new TreeNode(val,nullptr,root->right);
        root->left=lefti;
        root->right=righti;
    }
     solve(root->left,val,idx+1,depth);
    solve(root->right,val,idx+1,depth);
  }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* x=new TreeNode(val,root,nullptr);
            return x;
        }
        solve(root,val,1,depth);return root;
    }
};