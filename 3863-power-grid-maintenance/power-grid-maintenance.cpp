class UnionFind{
    private:
        vector<int>parent;
        vector<int>rank;
    
 public:
        UnionFind(int n):parent(n+1),rank(n+1,1){
            for(int i=1;i<=n;++i){
                parent[i]=i;
            }
        }
        int find(int x){
            if(parent[x]!=x){
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }
        void unite(int x,int y){
            int rootx=find(x);
            int rooty=find(y);
            if(rootx!=rooty){
                if(rank[rootx]>rank[rooty]){
                    parent[rooty]=rootx;
                    
                }
                else if(rank[rootx]<rank[rooty])parent[rootx]=rooty;
                else{
                    parent[rooty]=rootx;
                    rank[rootx]++;
                }
                
            }
        }
     

        
    };

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& con, vector<vector<int>>& qu) {
        UnionFind uf(c);
        for(const auto& co:con){
            uf.unite(co[0],co[1]);
            
        }
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>compo;
        vector<bool>ka(c+1,1);
        for(int i=1;i<=c;++i){
            int root=uf.find(i);
            compo[root].push(i);
        }
        vector<int>ans;
        for(const auto& q:qu){
            int type=q[0];
            int x=q[1];
            if(type==1){
                if(ka[x])ans.push_back(x);
            else
            {
                int root=uf.find(x);
                if(compo[root].empty())ans.push_back(-1);
                else{
                    while(!compo[root].empty()&&!ka[compo[root].top()])compo[root].pop();
                    if(compo[root].empty())ans.push_back(-1);
                    else
                        ans.push_back(compo[root].top());
                }
            }
            }
            else if(type==2)ka[x]=0;
            
            
        }
        return ans;
        
        
    }
};