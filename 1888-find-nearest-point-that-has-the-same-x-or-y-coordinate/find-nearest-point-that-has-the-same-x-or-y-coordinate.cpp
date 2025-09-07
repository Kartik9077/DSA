class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int n = points.size();
        int dist = INT_MAX;

        for(int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            if(x==x1 || y==y1) {
                int temp = abs(x1 - x) + abs(y1 - y);
                if(temp < dist) {
                    ans = i;
                    dist = temp;
                }
            }
        }

        return ans;
    }
};