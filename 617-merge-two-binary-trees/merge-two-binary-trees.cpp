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
    if(!r1&&!r2)return nullptr;
    int su=(r1?r1->val:0) + (r2? r2->val:0);
    TreeNode* root=new TreeNode(su);
      root->left=solve(r1?r1->left:nullptr,r2?r2->left:nullptr);
    root->right=solve(r1?r1->right:nullptr,r2?r2->right:nullptr);
  
    return root;
  }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
};