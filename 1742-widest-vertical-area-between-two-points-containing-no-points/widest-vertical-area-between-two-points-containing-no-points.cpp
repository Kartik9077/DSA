class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
         int max_width=0;
        int width=0;
        int n=points.size();
        vector<int>vertical;
        for(int i=0;i<n;i++){
           vertical.push_back(points[i][0]);
        }
        sort(vertical.begin(),vertical.end());
        for(int i=0;i<n-1;i++){
            width=vertical[i+1]-vertical[i];
            max_width=max(max_width,width);
        }
        return max_width;
    }
};