class Solution {
public:
int checker(int i,int j,vector<vector<int>>&dp,vector<int>&prices,int fee){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j==1){
            return dp[i][j]=max(-prices[i]+checker(i+1,0,dp,prices,fee),checker(i+1,1,dp,prices,fee));
        }
        else{
            return dp[i][j]=max(prices[i]+checker(i+1,1,dp,prices,fee)-fee,checker(i+1,j,dp,prices,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
          int n=prices.size();
        vector<vector<int>>dp(n,(vector<int>(3,-1)));
        return checker(0,1,dp,prices,fee);
    }
};