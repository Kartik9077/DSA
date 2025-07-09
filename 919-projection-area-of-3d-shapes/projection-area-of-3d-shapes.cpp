class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        for(int i = 0; i < n; i++){
            int rowmax = 0, colmax = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j]) ans++;
                rowmax = max(rowmax , grid[i][j]);
                colmax = max(colmax , grid[j][i]);
            }
            ans += rowmax + colmax;
        }
        return ans;
    }
};