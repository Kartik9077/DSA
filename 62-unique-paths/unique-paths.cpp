class Solution {
    int solve(int n,int m,int i,int j,vector<vector<int>>&dp){ 
        if(i<0||i>=n||j<0||j>=m)return 0;
        if(i==n-1&&j==m-1){
            return 1;
        }
       
        if(dp[i][j]!=0)return dp[i][j];
        return dp[i][j]=solve(n,m,i+1,j,dp)+solve(n,m,i,j+1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n));
         return solve(m,n,0,0,dp);    
    }
};