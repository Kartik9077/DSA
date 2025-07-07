class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                for(int j=1;j<=k;j++){
                    if(buy) curr[buy][j] = max(-prices[i]+after[0][j],0+after[1][j]);
                    else curr[buy][j] = max(prices[i]+after[1][j-1],0+after[0][j]);
                }
                after = curr;
            }
        }
        return after[1][k];
    }
};