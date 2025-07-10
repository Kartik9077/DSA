class Solution {
public:
    bool checkPalindrome(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] != s[j]) return dp[i][j] = 0;
        return dp[i][j] = checkPalindrome(i + 1, j - 1, s, dp);
    }

    int countSubstrings(string s) {
        int n = s.length(), count = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkPalindrome(i, j, s, dp)) {
                    count++;
                }
            }
        }

        return count;
    }
};