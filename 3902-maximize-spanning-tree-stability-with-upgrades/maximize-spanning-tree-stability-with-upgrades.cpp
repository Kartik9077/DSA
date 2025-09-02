class DisjointSet{
public: 
    vector<int> parent,rank,size;

    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        size.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void union_by_size(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(size[ulp_u] >= size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:

    static bool cmp(vector<int>& a,vector<int>& b){
        return a[2] > b[2];
    }

    int f(int currStability, int nodes,vector<vector<int>>& edges,int k){
        DisjointSet ds(nodes+1);
        int currMin = 1e9;
        for(int i=0; i<edges.size(); i++){
            if(edges[i][3]) {
                int ulp_1 = ds.findUPar(edges[i][0]);
                int ulp_2 = ds.findUPar(edges[i][1]);
                if(ulp_1 == ulp_2) return 0;
                ds.union_by_size(edges[i][0],edges[i][1]);
                currMin = min(currMin,edges[i][2]);
            }
            if(currMin < currStability) return 0;
        }

        for(int i=0; i<edges.size(); i++){
            if(!edges[i][3]){
                int ulp_1 = ds.findUPar(edges[i][0]);
                int ulp_2 = ds.findUPar(edges[i][1]);

                if(ulp_1 == ulp_2 || (k <= 0 && edges[i][2] < currStability)) continue;
                if(edges[i][2] >= currStability) {
                    ds.union_by_size(edges[i][0],edges[i][1]);
                } else if(k > 0 && 2*edges[i][2] >= currStability){
                    ds.union_by_size(edges[i][0],edges[i][1]);
                    k--;
                }
            }
        }
        return (ds.size[ds.findUPar(0)] == nodes);
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),cmp);
        int low = edges.back()[2], high = 2*edges[0][2];
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(f(mid,n,edges,k)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

auto bpsn = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'sk';
}();