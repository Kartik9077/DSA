class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>mpp;
        for(int i=0;i<wall.size();i++){
            __int128 sum=0;
            for(int j=0;j<wall[i].size()-1;j++){
                sum+=wall[i][j];
                mpp[sum]++;
            }
        }
        int ans=wall.size();
        for(auto it:mpp){
            ans=min(ans,int(wall.size())-it.second);
        }
        return ans;
    }
};