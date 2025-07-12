class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> set;

        int r = 0, l = 0;
        int ans = 0;

        while(r<n){
            int count=0;
            
            if(!set.count(s[r])){
                set.insert(s[r]);   
                ans = max(ans, r - l + 1);
                r++;
            } else {
                set.erase(s[l]);
                l++;
            }        
        }

        return ans;
    }
};