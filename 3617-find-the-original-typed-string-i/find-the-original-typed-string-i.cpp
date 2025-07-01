class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        char prev='1';
        for(auto it:word)
        {
            if(it==prev)ans++;
            prev=it;

        }
        return ans;

    }
};