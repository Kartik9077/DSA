class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        int curr=0;
        for(int i=1;i<n;i++){
            curr=max(0,curr+nums[i]-nums[i-1]);
            dp[i]=max(dp[i-1],curr);
        }
        return dp[n-1];
    }
};