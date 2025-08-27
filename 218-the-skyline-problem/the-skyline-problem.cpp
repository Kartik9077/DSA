class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> pq;
        pq.insert(0); 
        vector<vector<int>> ans;
        vector<pair<int,int>> points;

        for (auto &b : buildings) {
            points.push_back({b[0], -b[2]}); 
            points.push_back({b[1],  b[2]}); 
        }

        sort(points.begin(), points.end());

        int currHeight = 0;

        for (auto &p : points) {
            int x = p.first;
            int h = p.second;

            if (h < 0) pq.insert(-h);  
            else pq.erase(pq.find(h));  

            int pqTop = *pq.rbegin();   
            if (currHeight != pqTop) {
                currHeight = pqTop;
                ans.push_back({x, currHeight});
            }
        }
        return ans;
    }
};