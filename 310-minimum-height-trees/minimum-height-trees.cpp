class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        int i,j;
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        queue<int> q;
        if(n==1)
        {
            return {0};
        }
        for(auto e:edges)
        {
            
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
                degree[e[0]]++;
                degree[e[1]]++;
            
        }
        for(i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }
        int remaining = n;
        while(remaining>2)
        {
            int size = q.size();
            remaining-=size;
            for(i=0;i<size;i++)
            {
                int node = q.front();
                q.pop();
                for(auto it:adj[node])
                {
                    degree[it]--;
                    if(degree[it]==1)
                    {
                        q.push(it);
                    }
                }
                
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;

    }
};