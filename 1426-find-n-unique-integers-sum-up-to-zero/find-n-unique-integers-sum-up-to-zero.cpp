class Solution {
public:
    vector<int> sumZero(int n) {
        int a=n/2;vector<int>ans;
        for(int i=-a;i<0;i++)ans.push_back(i);
        if(n&1)ans.push_back(0);
        for(int i=1;i<=a;i++)ans.push_back(i);
        return ans;
    }
};