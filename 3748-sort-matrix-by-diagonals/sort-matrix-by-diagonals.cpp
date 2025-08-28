class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        size_t n = grid.size();
        vector<int> vec;
        vec.reserve(n);
        for (size_t i = n-1; i != 0; --i) {
            vec.clear();
            for (size_t j = 0; i+j != n; ++j) {
                vec.push_back(grid[j][i+j]);
            }
            sort(vec.begin(), vec.end());
            for (size_t j = 0; i+j != n; ++j) {
                grid[j][i+j] = vec[j];
            }
        }
        for (size_t i = 0; i != n; ++i) {
            vec.clear();
            for (size_t j = 0; i+j != n; ++j) {
                vec.push_back(grid[i+j][j]);
            }
            sort(vec.begin(), vec.end(), greater<int>());
            for (size_t j = 0; i+j != n; ++j) {
                grid[i+j][j] = vec[j];
            }
        }

        return grid;
    }
};