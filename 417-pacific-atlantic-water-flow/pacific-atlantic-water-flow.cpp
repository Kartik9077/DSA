class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows;
    int cols;
    vector<vector<int> > h;
    vector<vector<bool>> bfs(queue<pair<int, int>> &qu) {
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        while(qu.size()>0) {
            auto cell = qu.front();
            qu.pop();
            int i = cell.first;
            int j = cell.second;
            visited[i][j] = true;
            for(int d = 0; d < 4; d++) {
                int newRow = i + dir[d][0];
                int newCol = j + dir[d][1];
                if(newRow < 0 or newCol < 0 or newRow >= rows or newCol >= cols) continue;
                if(visited[newRow][newCol]) continue;
                if(h[newRow][newCol] < h[i][j]) continue;
                qu.push({newRow, newCol});
            }
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        h = heights;
        queue<pair<int, int>> pacificbfs;
        queue<pair<int, int>> atlanticbfs;
        for(int i = 0; i < rows; i++) {
            pacificbfs.push({i, 0});
            atlanticbfs.push({i, cols-1});
        }
        for(int j = 1; j < cols; j++) {
            pacificbfs.push({0, j});
        }
        for(int j = 0; j < cols-1; j++) {
            atlanticbfs.push({rows-1, j});
        }
        vector<vector<bool>> pacific = bfs(pacificbfs);
        vector<vector<bool>> atlantic = bfs(atlanticbfs);

        vector<vector<int> > result;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
};