class Solution {
public:
    int dp[1001][1001];
    vector<int> num;
    int n;
    int rec(int x, int y) {
        if (x >= y || x >= n || y >= n)
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        int ans = 0;
        for (int k = y + 1; k < n; k++) {
            if (num[k] == ((2 * ((long long)num[y])) - num[x])) {
                ans += 1 + rec(y, k);
            }
        }
        dp[x][y] = ans;
        return ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        n = nums.size();
        num = nums;
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += rec(i, j);
            }
        }
        return ans;
    }
};