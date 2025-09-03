class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
         int n = img.size(), m = img[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = 0, count = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            sum += img[x][y] & 0xFF;
                            ++count;
                        }
                    }
                }
                img[i][j] |= (sum / count) << 8;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) img[i][j] >>= 8;
        }
        return img;
    }
};