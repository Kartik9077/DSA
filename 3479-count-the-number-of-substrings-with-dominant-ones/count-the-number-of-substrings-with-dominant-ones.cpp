class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> prefix(n);
        prefix[0] = s[0] - '0';
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (s[i] - '0');
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int ones = prefix[j];
                if(i != 0) ones -= prefix[i - 1];
                int zeroes = j - i + 1 - ones;
                if(ones < zeroes * zeroes) {
                    int diff = zeroes * zeroes - ones;
                    j += diff - 1;
                } else {
                    int diff = sqrt(ones) - zeroes;
                    int nextj = j + diff;
                    if(nextj >= n) {
                        ans += n - j;
                    } else {
                        ans += diff + 1;
                    }
                    j = nextj;
                }
            }
        }
        return ans;
    }
};