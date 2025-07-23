class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        int n=arr.size();
        vector<int>dp(n+1);
        for(int i=0;i<=n;i++){
            int curr=0,b=0;
            for(int k=1;k<=K&&i-k>=0;++k){
                curr=max(curr,arr[i-k]);
                b=max(b,dp[i-k]+curr*k);
            }
            dp[i]=b;
        }
        return dp[n];
    }
};