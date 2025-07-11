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
    void solve(TreeNode*  root,vector<int>&a)
    {  if(root==nullptr)return;
        if(root->right==nullptr&&root->left==nullptr){
           a.push_back(root->val);return;
        }
        solve(root->left,a),solve(root->right,a);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        solve(root1,a);solve(root2,b);
        if(a.size()!=b.size())return 0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])return 0;
        }return 1;
        
    }
};