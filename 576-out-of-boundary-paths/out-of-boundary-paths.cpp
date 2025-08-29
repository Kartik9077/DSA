class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<vector<int>>> dp;
    
    int dfs(int r, int c, int moves) {
        if (r < 0 || r >= m || c < 0 || c >= n) return 1;
        if (moves == 0) return 0;
        if (dp[r][c][moves] != -1) return dp[r][c][moves];
        long long ways = 0;
        ways += dfs(r-1, c, moves-1);
        ways += dfs(r+1, c, moves-1);
        ways += dfs(r, c-1, moves-1);
        ways += dfs(r, c+1, moves-1);
        
        return dp[r][c][moves] = ways % MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m; this->n = n;
        dp.assign(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return dfs(startRow, startColumn, maxMove);
    }
};