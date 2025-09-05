class Solution {
public:
    int heightChecker(vector<int>& he) {
        vector<int>h=he;int ans=0;
        sort(h.begin(),h.end());
        for(int i=0;i<he.size();i++)if(h[i]!=he[i])ans++;
        return ans;
    }
};