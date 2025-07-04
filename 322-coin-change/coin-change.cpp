class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,-1);
        vector<int>cur(amount+1,-1);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                int take=(coins[i]<=amt)?1+cur[amt-coins[i]]:1e9;
                int nottake=prev[amt];
                cur[amt]=min(take,nottake);
            }
            prev=cur;
        }
        if(prev[amount]==1e9) return -1;
        return prev[amount];
    }
};