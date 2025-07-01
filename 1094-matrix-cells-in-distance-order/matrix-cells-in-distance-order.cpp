class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j) res.push_back({i , j});
        }
        sort(res.begin() , res.end() , [rCenter , cCenter](const vector<int>& a , const vector<int>& b){
            int x = abs(a[0] - rCenter) + abs(a[1] - cCenter); 
            int y = abs(b[0] - rCenter) + abs(b[1] - cCenter);
            return y > x;
        });
        return res;
    }
};