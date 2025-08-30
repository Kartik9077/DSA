class Solution {
public:
    int bfs(vector<vector<int>>& adj, int node){
        int ans = 0;
        int n = adj.size();

        vector<int> visited(n, 0);

        queue<int> q;


        q.push(node);
        visited[node] = 1;

        while(!(q.empty())){
            int cur = q.front();
            q.pop();
            ans++;
            for(auto it: adj[cur]){
                if(visited[it] == 0){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }

        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();

        vector<vector<int>> adj(n);

        int p1, p2;

        for(int i = 0;i<bombs.size();i++){
            for(int j = 0;j<bombs.size();j++){
               long long dx = (long long)bombs[i][0] - bombs[j][0];
                long long dy = (long long)bombs[i][1] - bombs[j][1];

                long long p1 = dx * dx;
                long long p2 = dy * dy;

                long long r3 = (long long)bombs[i][2] * bombs[i][2];
                if(p1+p2 <= r3){
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 1;

      
        for(int i = 0;i<n;i++){
            int cur = bfs(adj, i);
            ans = max(ans, cur);
        }

        return ans;
        
    }
};