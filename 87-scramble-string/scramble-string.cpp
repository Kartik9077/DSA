class Solution {
public:
    bool f(string s1, string s2,
           unordered_map<string, unordered_map<string, bool>>& dp) {
        if (s1.length() != s2.length())
            return false;
        if (s1 == s2)
            return true;
        if (s1.length() == 1) {
            return s1 == s2;
        }

        if (dp[s1].find(s2) != dp[s1].end())
            return dp[s1][s2];
        for (int idx = 1; idx < s1.length(); idx++) {
            string x = s1.substr(0, idx);
            string y = s1.substr(idx);
            if (f(x, s2.substr(0, idx), dp) && f(y, s2.substr(idx), dp))
                return dp[s1][s2] = true;
            if (f(x, s2.substr(y.length()), dp) &&
                f(y, s2.substr(0, y.length()), dp))
                return dp[s1][s2] = true;
        }

        return dp[s1][s2] = false;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        unordered_map<string, unordered_map<string, bool>> dp;
        vector<int> f1(26, 0), f2(26, 0);
        for (int i = 0; i < n; i++) {
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (f1[i] != f2[i])
                return false;
        }
        return f(s1, s2, dp);
    }
};