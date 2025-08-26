class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiag = 0;
        int maxArea = 0;
        
        for (auto &d : dimensions) {
            int l = d[0], w = d[1];
            long long diagSq = 1LL * l * l + 1LL * w * w;
            int area = l * w;
            
            if (diagSq > maxDiag) {
                maxDiag = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiag && area > maxArea) {
                maxArea = area;
            }
        }
        
        return maxArea;
    }
};