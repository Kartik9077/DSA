class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
          if(n==0)return dp[n];
        dp[1]=10;
        int curr=dp[1]-dp[0];
        for(int i=2;i<=n;i++){
        curr *= (10 - (i - 1));
         dp[i]+=dp[i-1]+curr;
        }
        return dp[n];
        
    }
};