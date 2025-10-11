class Solution {
public:
    int minCharacters(string a, string b) {
        const int n = a.length(), m = b.length();
        int f1[26] = {0}, f2[26] = {0};
        for(int i = 0; i < n; ++i) ++f1[a[i] - 'a'];
        for(int i = 0; i < m; ++i) ++f2[b[i] - 'a'];
        int res = n + m;
        int p1 = 0, p2 = 0;
        for(int i = 0; i < 25; ++i) {
            int freq1 = f1[i], freq2 = f2[i];
            res = min(res, n - freq1 + m - freq2);
            p1 += freq1;
            p2 += freq2;
            res = min(res, n - p1 + p2);
            res = min(res, m - p2 + p1);
        }
        return min(res, n - f1[25] + m - f2[25]);
    }
};