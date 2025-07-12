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
    int maxii=0;
    void dfs(TreeNode* root,bool left,int ans){
        if(root==nullptr)return ;
        maxii=max(maxii,ans);
        if(left)
        {dfs(root->right,0,ans+1);dfs(root->left,1,1);}
        else{
            dfs(root->left,1,ans+1);dfs(root->right,0,1);
        }


    }

public:
    int longestZigZag(TreeNode* root) {
        int ans=0;
        dfs(root,0,ans);
        return maxii;
        
    }
};