
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int n : nums) {
            for (int i = target; i >= n; i--) {
                if (dp[i]) continue;
                if (dp[i - n]) dp[i] = true;
                if (dp[target]) return true;
            }
        }

        return false;        
    }
};