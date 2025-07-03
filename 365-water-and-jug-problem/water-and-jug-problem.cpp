class Solution {
public:
    bool canMeasureWater(int x, int y, int tar) {
        vector<vector<int>> vis(x+1,vector<int>(y+1,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();
            if(i == tar || j == tar || (i + j == tar)) {
                return true;
            }
            vector<pair<int,int>> nxt = {
                {x,j}, {i,y}, {0,j}, {i,0}
            };
            int t = i + j;
            int nj = min(t, y);
            int ni = t - nj;
            nxt.push_back({ni, nj});
            int in = min(t, x);
            int ij = t - in;
            nxt.push_back({in, ij});
            for(auto [a, b] : nxt) {
                if(a >= 0 && a <= x && b >= 0 && b <= y && !vis[a][b]) {
                    vis[a][b] = 1;
                    q.push({a, b});
                }
            }
        }
        return false;
    }
};