class Solution {
public:
    void helper(int l, int r, string& s, vector<int>& dp) {
        int n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (l == 0)
                dp[r] = 0;
            else
                dp[r] = min(dp[r], dp[l - 1] + 1);
            l--;
            r++;
        }
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            helper(i, i, s, dp);     
            helper(i, i + 1, s, dp);
        }
        return dp[n - 1];
        //y
    }
};
