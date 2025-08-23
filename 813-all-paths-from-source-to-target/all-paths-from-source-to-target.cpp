class Solution {
public:
 void dfs(vector<vector<int>>&g,int n,vector<int>&ans,vector<vector<int>>&res,int i){
    if(ans.back()==n-1){
        res.push_back(ans);
    }
    for(auto it:g[i]){
        ans.push_back(it);
        dfs(g,n,ans,res,it);
        ans.pop_back();
    }
 }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>ans;
        vector<vector<int>>res;
        int i=0;
        ans.push_back(0);
        dfs(g,n,ans,res,i);
        return res;
    }
};