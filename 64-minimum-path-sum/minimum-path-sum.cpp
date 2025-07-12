
class Solution {
public:
int solve(vector<vector<int>>&grid,int i,int j,int n,int m,vector<vector<int>>&dp){
  if(i>=n||j>=m)return INT_MAX;
   if(i==n-1&&j==m-1){
    return grid[i][j]+dp[i][j];
  }
  if(dp[i][j]!=0)return dp[i][j];
   int right=solve(grid,i,j+1,n,m,dp);
   int left=solve(grid,i+1,j,n,m,dp);
    dp[i][j]=min(left,right)+grid[i][j];
    return dp[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        return solve(grid,0,0,n,m,dp);  
    }
};