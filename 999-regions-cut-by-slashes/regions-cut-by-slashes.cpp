class Solution {
    int max_idx{-1};

public:
    void traverse(int x, int y,vector<vector<bool>> &filled) {
        if (x < 0 || x > max_idx || y < 0 || y > max_idx) {
            return;
        }
        if (filled[x][y]) {
            return;
        }
        filled[x][y] = true;

        traverse(x + 1, y, filled);
        traverse(x, y + 1, filled);
        traverse(x - 1, y, filled);
        traverse(x, y - 1, filled);
        return;
    };

    

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        max_idx = n * 4;
        vector<vector<bool>> filled(max_idx + 1, vector<bool> (max_idx + 1, false));

        int regions = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                int x1 =  4 * j;
                int y1 = 4 * i;
                if (c == '/') {
                    x1 += 4;
                    for (int k = 0; k <= 4; k++) {                        
                        filled[y1 + k][x1 - k] = true;
                    }
                } else if (c == '\\') {
                    x1 = 4 * j;
                    for (int k = 0; k <= 4; k++) {
                        filled[y1 + k][x1 + k] = true;
                    }
                } else {
                    continue;
                }
            }
        }
        
        for (int i = 0; i < max_idx + 1; i++) {
            for (int j = 0; j < max_idx + 1; j++) {
                if (filled[i][j]) {
                    continue;
                }
                regions++;
                traverse(i, j, filled);
            }
        }


        return regions;
    }
};