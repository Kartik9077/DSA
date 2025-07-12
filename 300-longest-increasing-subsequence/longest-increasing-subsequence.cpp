class Solution {
public:
    int ans(int ind, int prev, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (ind == n) return 0;

        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];

        int t = INT_MIN;
        if (prev == -1 || nums[ind] > nums[prev])
            t = 1 + ans(ind + 1, ind, nums, n, dp);

        int nt = ans(ind + 1, prev, nums, n, dp);

        return dp[ind][prev + 1] = max(t, nt);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return ans(0, -1, nums, n, dp);
    }
};