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
  void solve(TreeNode* root,int &sum){
    if(root==nullptr)return;
     if(root->right)solve(root->right,sum);
     if(root->left){
        if(root->left->right==nullptr&&root->left->left==nullptr)sum+=root->left->val;
        solve(root->left,sum);
     }

  }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        solve(root,sum);
        return sum;
        
    }
};