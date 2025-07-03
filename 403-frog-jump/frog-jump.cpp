class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>>dp;
        for(auto it:stones){
            dp[it]=unordered_set<int>();
        }
        
        dp[0].insert(1);
        for(int stone : stones){
            for(int jump : dp[stone]){
                int reach = stone+jump;
                if(reach == stones.back()) return true;
                if(dp.count(reach)){
                    if(jump - 1>0) dp[reach].insert(jump-1);
                    dp[reach].insert(jump);
                    dp[reach].insert(jump+1);
                }
            }
        }
        return false;
        
    }
};