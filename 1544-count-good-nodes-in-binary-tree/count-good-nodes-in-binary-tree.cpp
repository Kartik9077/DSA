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
    void solve(TreeNode* root,int &ans,int maxi){
        if(root==nullptr)return;
        if(root->val>=maxi){
            ans+=1;
        }
        maxi=max(maxi,root->val);
        solve(root->left,ans,maxi);
        solve(root->right,ans,maxi);

        
    }
public:
    int goodNodes(TreeNode* root) {
        int ans=0;
        solve(root,ans,INT_MIN);
        return ans;
     
    }
};