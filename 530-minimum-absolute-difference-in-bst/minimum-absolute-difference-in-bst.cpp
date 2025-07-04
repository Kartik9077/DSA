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
void solve(vector<int>&a,TreeNode* root){
    if(root==nullptr)return;
    a.push_back(root->val);
    solve(a,root->right);
    solve(a,root->left);
}
    int getMinimumDifference(TreeNode* root) {
        vector<int>a;
        int diff=INT_MAX;
        solve(a,root);sort(a.begin(),a.end());
        for(int i=0;i<a.size()-1;i++){
            diff=min(diff,abs(a[i+1]-a[i]));
        }
        return diff;

    }
};