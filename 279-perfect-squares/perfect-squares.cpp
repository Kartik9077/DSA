class Solution {
public:
    int numSquares(int n) 
    {
        vector<int>dp(n+1, -1);
        dp[0] = 0;
        for(int k = 1; k <= n; k++)
        {
            int ans = 1e9;
            for(int i = 1; i * i <= n; i++)
            {
                if(k - i*i >= 0)
                ans = min(ans, 1 + dp[k- i*i]);
            }
            dp[k] = ans;
        }
        return dp[n];
    }
};