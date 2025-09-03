class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
          sort(points.begin(), points.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
            });

        int n = points.size(), result = 0;

        for(int uL = 0; uL < n; uL++){ 
            int prevACY = INT_MIN; 
            for(int lR = uL + 1; lR < n; lR++){
                
                if( points[uL][1] < points[lR][1] ||points[lR][1] <= prevACY){ 
                    continue;
                }

                result++;
                prevACY = points[lR][1];

            }
        }

        return result;
    }
};