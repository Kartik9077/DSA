class Solution {
private: 
    int lcs(string word1, string word2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
           
        }
       return dp[n][m]; 
    }    
public:
    int minDistance(string word1, string word2) {
          
          int n = word1.size(), m = word2.size();
          int commonLen = lcs(word1, word2, n, m);
          return(n + m - (2 * commonLen));
    }
};