class Solution {
public:
    int dp[30001];
    string str;
    int n;
    int rec(int i) {
        if (i >  n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = 0, count = 0;
        for (int k = i; k < n; k++) {
            if (str[k] == '(')
                count++;
            else
                count--;
            if (count < 0)
                break;
            if (count == 0) {
                ans = max(ans, k - i + 1 + rec(k + 1));
            }
        }
        dp[i] = ans;
        return ans;
    }
    int longestValidParentheses(string s) {
        n = s.length();
        str = s;
        int val = 0;
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < n; i++) {
            val = max(rec(i), val);
        }
        return val;
    }
};