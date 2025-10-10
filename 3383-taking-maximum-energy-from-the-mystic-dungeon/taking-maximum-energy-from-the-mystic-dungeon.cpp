class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(k, 0);
        int result = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {
            dp[i % k] = energy[i] + ((i + k < n) ? dp[(i + k) % k] : 0);
            result = max(result, dp[i % k]);
        }

        return result;
    }
};