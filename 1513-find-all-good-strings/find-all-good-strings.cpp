class Solution {
public:
    int mod = 1e9+7;
    vector<int> lps;
    int n, e;
    string s1, s2, evil;
    int dp[501][51][2][2];
    vector<int> computeLPS(const string& pattern) {
        int n = pattern.size();
        lps.resize(n);
        lps[0] = 0;
        int length = 0;
        int i = 1;
        while (i < n) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int dfs(int i, int e_i, bool isS1Prefix, bool isS2Prefix){
        if(e_i >= e) return 0;
        if(i >= n) return 1;
        if(dp[i][e_i][isS1Prefix][isS2Prefix] != -1){
            return dp[i][e_i][isS1Prefix][isS2Prefix];
        }
        int start = isS1Prefix ? s1[i]:'a';
        int end = isS2Prefix ? s2[i]:'z';
        int ans = 0;
        for(char ch=start; ch<=end; ch++){
            int temp_e_i = e_i;
            while(temp_e_i > 0 && ch != evil[temp_e_i]){
                temp_e_i = lps[temp_e_i - 1];
            }
            if (ch == evil[temp_e_i]) {
                temp_e_i += 1;
            }
            ans = (ans + dfs(i + 1, temp_e_i, isS1Prefix && ch == start, isS2Prefix && ch == end)) % mod;
        }
        return dp[i][e_i][isS1Prefix][isS2Prefix]=ans;
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        this->lps=computeLPS(evil);
        this->n=n;
        this->e=evil.size();
        this->s1=s1;
        this->s2=s2;
        this->evil=evil;
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,1,1)%mod;
    }
};