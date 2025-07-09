class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
          int r=grid.size(), c=grid[0].size();
        vector<vector<int>> ans(r, vector<int>(c));
        k = k % (r*c);
        for(int i=0; i<(r*c); i++){
            int v = (i+k)%(r*c);
            int x = v/c;
            int y = v%c;
            ans[x][y] = grid[i/c][i%c];
        }
        return ans;
    }
};