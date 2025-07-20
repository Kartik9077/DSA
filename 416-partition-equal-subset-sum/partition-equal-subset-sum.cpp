
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t=accumulate(nums.begin(),nums.end(),0);
        if (t%2!=0)return 0;
        int target=t/2;
        vector<bool>dp(target+1,0);
        dp[0]=1;
        for (int n:nums) {
            for (int i=target;i>=n;i--) {
              
                if(dp[i-n])dp[i]=1;
                if(dp[target])return 1;
            }
        }

        return 0;        
    }
};