class Solution {
public:
    string originalDigits(string s) {
        int freq[26] = {0}, cnt[10] = {0};
        for(int i = 0, n = s.length(); i < n; ++i) ++freq[s[i] - 'a'];
        cnt[0] = freq['z' - 'a'];
        cnt[2] = freq['w' - 'a'];
        cnt[4] = freq['u' - 'a'];
        cnt[6] = freq['x' - 'a'];
        cnt[8] = freq['g' - 'a'];

        cnt[3] = freq['h' - 'a'] - cnt[8];
        cnt[5] = freq['f' - 'a'] - cnt[4];
        cnt[7] = freq['s' - 'a'] - cnt[6];
        cnt[1] = freq['o' - 'a'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = freq['i' - 'a'] - cnt[5] - cnt[6] - cnt[8];
        string res;
        for(int i = 0; i < 10; ++i) res.append(cnt[i], '0' + i);
        return res;
    }
};