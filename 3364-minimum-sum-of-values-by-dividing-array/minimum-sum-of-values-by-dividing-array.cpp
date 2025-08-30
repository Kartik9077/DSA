class Solution {
public:
    vector<vector<map<int,int>>>dp;
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n=nums.size();
        int m=andValues.size();
        dp.resize(n,vector<map<int,int>>(m));
        int ans=find(nums,0,andValues,0,n,m,-1);
        if(ans>=1e8)ans=-1;
        return ans;
    }
    int find(vector<int>& nums,int i,vector<int>& av,int j,int &n,int &m,int a){
        if(i>=n && j>=m)return 0;
        if(j>=m || i>=n)return 1e8;
        if(dp[i][j].find(a)!=dp[i][j].end())return dp[i][j][a];
        if(a==-1)a=nums[i];
        else a&=nums[i];
        int ans=find(nums,i+1,av,j,n,m,a);
        if(a==av[j])
            ans=min(ans,nums[i]+find(nums,i+1,av,j+1,n,m,-1));  
        return dp[i][j][a]=ans;  
    }
};