class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis=abs(target[0])+abs(target[1]);
        for(auto it:ghosts){
            if(abs(target[0]-it[0])+abs(target[1]-it[1])<=dis)return 0;

        }
        return 1;
    }
};