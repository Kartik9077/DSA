class Solution {
 void dfs(vector<int>adj[], vector<int>&nums, int node, int par, vector<int>&res, vector<pair<int, int>>latest[], int height)
    {
        int best = -1, ans = -1;
          for(int i=1; i<=50; i++)
          {
            if(!latest[i].empty() && gcd(nums[node], i) == 1)
            {
                pair<int, int>curr = latest[i].back();
                if(curr.second > best)
                {
                    best = curr.second;
                    ans = curr.first;
                }
            }
          }

        res[node] = ans;
        latest[nums[node]].push_back({node, height});

        for(auto &x: adj[node])
        {
            if(x != par)
            dfs(adj, nums, x, node, res, latest, height+1);
        }

        latest[nums[node]].pop_back();
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int>adj[n+1];

        for(auto &x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>res(n, -1);
        vector<pair<int, int>>latest[52];
        dfs(adj, nums, 0, -1, res, latest, 0);
        return res;
        
    }
};