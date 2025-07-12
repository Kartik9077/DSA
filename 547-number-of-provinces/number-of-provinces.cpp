class Solution {
public:
 void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int node) {
        vis[node] = 1;
        for (int j = 0; j < isConnected.size(); ++j) {
            if (isConnected[node][j] == 1 && !vis[j]) {
                dfs(isConnected, vis, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
         int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                provinces++;
                dfs(isConnected, vis, i);
            }
        }
        return provinces;
    }
};