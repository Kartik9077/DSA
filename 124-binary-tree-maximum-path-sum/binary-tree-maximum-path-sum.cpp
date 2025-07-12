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
    private:
    int check(TreeNode* root,int &maxi)
    {
      if(root==NULL)return 0;
      int ls=max(0,check(root->left,maxi));
      int rh=max(0,check(root->right,maxi));
      maxi=max(maxi,root->val+ls+rh);
      return (root->val)+(max(ls,rh));
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        check(root,maxi);
        return maxi;
    }
};