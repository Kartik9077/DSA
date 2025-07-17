class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k,vector<int>(k,0));
        int maxlen=0;
        for(auto num:nums){
            for(int j=0;j<k;j++){
                int rem=num%k;
                maxlen=max(maxlen,dp[rem][j]=dp[j][rem]+1);

            }
        }
        return maxlen;
        
        
 }
};