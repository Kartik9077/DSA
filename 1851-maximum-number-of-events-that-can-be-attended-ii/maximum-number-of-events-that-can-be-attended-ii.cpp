class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
         sort(events.begin(), events.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int n = events.size();
        vector<int> endTimes(n);
        for (int i = 0;i<n;++i)
            endTimes[i] = events[i][1];
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0], val = events[i - 1][2];
            int prev =
                upper_bound(endTimes.begin(), endTimes.end(), start - 1) -
                endTimes.begin();
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + val);
            }
        }

        return dp[n][k];
    }
};