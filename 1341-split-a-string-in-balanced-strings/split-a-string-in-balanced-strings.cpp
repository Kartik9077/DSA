class Solution {
public:
    int balancedStringSplit(string s) {
        int count_l=0,count_r=0;
        int ans=0;
        s[0]=='R'?count_r++:count_l++;
        for(int i=1;i<s.size();i++){
            if(count_l==count_r){
                ans++;count_l=0;count_r=0;
            }
            if(s[i]=='R')count_r++;
            else count_l++;
        }
        if(count_l&&count_l==count_r)ans++;
        return ans;

    }
};