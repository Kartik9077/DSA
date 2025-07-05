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
  TreeNode* solve(TreeNode* r1,TreeNode* r2){
    if(!r1)return r2;
    if(!r2)return r1;
    int su=(r1?r1->val:0) + (r2? r2->val:0);
    TreeNode* root=new TreeNode(su);
      root->left=solve(r1->left,r2->left);
    root->right=solve(r1->right,r2->right);
  
    return root;
  }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
};