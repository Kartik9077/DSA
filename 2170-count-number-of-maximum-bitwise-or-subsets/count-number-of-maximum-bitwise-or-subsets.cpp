class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
    int ori=0;
    vector<int>dp(131073,0);
    dp[0]=1;
    for(auto a:nums){
       for(int i=ori;i>=0;i--)dp[i|a]+=dp[i];
       ori|=a;

    }
    return dp[ori];

    }
};