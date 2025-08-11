class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int to_gas=0,to_cost=0;
        for(int i=0;i<n;i++){
            to_gas+=gas[i];
            to_cost+=cost[i];
        }
        if(to_cost>to_gas)return -1;
        int cur_gas=0,ans=0;
        for(int i=0;i<n;i++){
            cur_gas+=gas[i];
            cur_gas-=cost[i];
            if(cur_gas<0){cur_gas=0;ans=i+1;}

        }
        return ans;
    }
};