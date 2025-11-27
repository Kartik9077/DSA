class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
          int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        vector<long long> dp(n + 1, -1e18);
        dp[0] = 0; 

        long long ans = LLONG_MIN;
        for (int i = k; i <= n; i++) {
            dp[i] = max(prefix[i]-prefix[i-k], dp[i - k] + (prefix[i] - prefix[i - k]));
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};