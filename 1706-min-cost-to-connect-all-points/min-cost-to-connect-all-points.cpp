class DSU{
    public:
    vector<int> parent,size;

    DSU(int n){
        parent.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int find(int x){ 
        if(parent[x]==x) return x;
        return find(parent[x]);
    }   

    void joinBySize(int u,int v){
        u=find(u), v=find(v);
        if(u==v) return;
        if(size[u]>size[v]){
            parent[v]=u;
            size[u]+=size[v];
        }
        else{
            parent[u]=v;
            size[v]+=size[u];
        }
    }

    bool isInSameComponent(int u,int v){
        return find(u) == find(v);
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>>pq;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push_back({dist,i,j});
            }
        }

        DSU graph(n);
        int cost = 0;
        sort(pq.begin(),pq.end());
        for(auto p:pq){
            int wei = p[0];
            int u = p[1];
            int v = p[2];
            if(graph.isInSameComponent(u,v)) continue;
            cost += wei;
            graph.joinBySize(u,v);

        }

        return cost;
    }
};