class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),curr=0;
        vector<int>dp(n,0);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {  curr=max(0,curr+prices[i]-prices[i-1]);
            dp[i]=max(dp[i-1],curr);
        }

        return dp[n-1];
        
    }
};