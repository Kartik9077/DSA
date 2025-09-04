class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        map<int, int> rows;
        map<int, int> cols;
        for (int i = 0; i < indices.size(); i++) {
            rows[indices[i][0]]++;
            cols[indices[i][1]]++;
        }

        int even_rows = m, even_cols = n;
        int odd_rows = 0, odd_cols = 0;

        for (auto pair : rows) {
            if (pair.second % 2 == 1) {
                odd_rows++;
                even_rows--;
            }
        }

        for (auto pair : cols) {
            if (pair.second % 2 == 1) {
                odd_cols++;
                even_cols--;
            }
        }

        int ans = odd_rows*even_cols + odd_cols*even_rows;
        return ans; 
    }
};