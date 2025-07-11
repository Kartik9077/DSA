class Solution {
public:
 struct VectorHash {
        template <typename T>
        std::size_t operator()(const std::vector<T>& vec) const {
            std::size_t seed = vec.size();
            for (const auto& elem : vec) {
                seed ^= std::hash<T>()(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }};
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<vector<int>, int, VectorHash> temp;
        int n = grid.size();
        for(int i = 0; i<n; i++){
            temp[grid[i]]++;
        }
        vector<int> gg(n,0);
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                gg[j] = grid[j][i];
            }
            ans+=temp[gg];
        }
        return ans;
    }
};