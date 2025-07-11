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
   void solve(TreeNode* root,int val,TreeNode* &x){
    if(root==nullptr)return;
    if(root->val==val){
        x=root;return;
    }
      solve(root->left,val,x);solve(root->right,val,x);
   }

    TreeNode* searchBST(TreeNode* root, int val) {
       TreeNode* x=nullptr;
       solve(root,val,x);
       return x;
        
    }
};