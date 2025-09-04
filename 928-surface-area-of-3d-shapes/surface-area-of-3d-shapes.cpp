class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size();

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        
        
        int total=0;

        for (int i=0;i<N;++i) {
            for (int j=0;j<N;++j) {
                int v = grid[i][j];

                if (v==0) {
                    continue;
                }

                total += 2;

                for (auto [dx, dy]: directions) {
                    int nx, ny;
                    nx = i + dx;
                    ny = j + dy;
                    if (nx < 0 or nx == N or ny < 0 or ny == N) {
                        total += v;
                        continue;
                    }

                    int v2 = grid[nx][ny];

                    int diff = v - v2;

                    if (diff > 0) {
                        total += diff;
                    }
                }


                
            }

        }


        return total;

    }
};