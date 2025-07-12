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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        map<int,int>mpp;
        if(root==nullptr)return 0;
        q.push(make_pair(root,1));
        int idx=1,curr=0;
        while(!q.empty()){
            if(q.front().second==idx){
                curr+=q.front().first->val;
                 TreeNode* x=q.front().first;
                q.pop();
               
                if(x->left)q.push(make_pair(x->left,idx+1));
                if(x->right)q.push(make_pair(x->right,idx+1));
            }
            else{
                mpp[idx]=curr;
                curr=0;
                idx+=1;
            }

        }
        mpp[idx]=curr;
        int ans=0,sum=INT_MIN;
        for(auto it:mpp){
            if(it.second==sum)continue;
            if(it.second>sum){
                ans=it.first;
                sum=it.second;
            }
           
            
        }
        return ans;
        
       
        
    }
};