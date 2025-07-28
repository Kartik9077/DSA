class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
    int ori=0;
    int dp[1<<17]={1};
    for(auto a:nums){
       for(int i=ori;i>=0;i--)dp[i|a]+=dp[i];
       ori|=a;

    }
    return dp[ori];

    }
};