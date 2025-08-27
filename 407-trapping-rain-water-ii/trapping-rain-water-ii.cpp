class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        const int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    pq.emplace(heightMap[i][j], i * n + j);
                    visited[i][j] = true;
                }
            }
        }
        
        int max_boundary = 0;
        while (!pq.empty()) {
            int h = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            int i = idx / n, j = idx % n;
            max_boundary = max(max_boundary, h);
            for (auto& dir : dirs) {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n || visited[ni][nj]) continue;
                if (heightMap[ni][nj] < max_boundary) res += max_boundary - heightMap[ni][nj];
                pq.emplace(heightMap[ni][nj], ni * n + nj);
                visited[ni][nj] = true;
            }
        }
        return res;
    }
};