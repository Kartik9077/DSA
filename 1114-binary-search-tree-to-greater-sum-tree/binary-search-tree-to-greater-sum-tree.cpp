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
void convert(TreeNode* root,unordered_map<int,long long>mpp){
    if(root==nullptr)return ;
    root->val=mpp[root->val];
    convert(root->left,mpp);
    convert(root->right,mpp);

}
  void solve(unordered_map<int,long long>&mpp,TreeNode* root){
    if(root==nullptr)return ;
    mpp[root->val]=root->val;
    solve(mpp,root->left);
    solve(mpp,root->right);
  }
    TreeNode* bstToGst(TreeNode* root) {
     unordered_map<int,long long>mpp;
     solve(mpp,root);
     vector<int>arr;
     for(auto it:mpp)arr.push_back(it.first);
     sort(arr.rbegin(),arr.rend());
     for(int i=1;i<arr.size();i++){
        mpp[arr[i]]+=mpp[arr[i-1]];
     }
     convert(root,mpp);
     return root;

     
    }
};