class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> freq;
        int maxi = 0;
        for(int i = 0, n = wall.size(); i < n; ++i){
            long long sum = 0;
            for(int j = 0, m = wall[i].size() - 1; j < m; ++j){
                sum += wall[i][j];
                maxi = max(maxi , ++freq[sum]);
            }
        }
        return wall.size() - maxi;
    }
};