class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int o=0,e=0;
        for(auto it:position){
            if(it&1)o++;
            else e++;
        }
        return min(e,o);
    }
};