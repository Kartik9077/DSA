class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        map<char, int> mp;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (i < n/2) c1 += mp[tolower(s[i])];
            else c2 += mp[tolower(s[i])];
        }
        return c1 == c2;
    }
};