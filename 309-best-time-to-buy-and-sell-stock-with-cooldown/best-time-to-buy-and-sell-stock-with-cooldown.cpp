class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        dp[n][0]=0;
        __int128 profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0)profit=max(-p[i]+dp[i+1][1],0+dp[i+1][0]);
                else profit=max(p[i]+dp[i+2][0],0+dp[i+1][1]);

                dp[i][j]=profit;
            }
        }
        return dp[0][0];
        
    }
};