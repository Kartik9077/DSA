class Solution {
public:
  int findp(vector<int>&p,int x){
    if(p[x]!=x){
        p[x]=findp(p,p[x]);

    }
    return p[x];
  }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>p(n+1);
        for(int i=1;i<=n;i++)p[i]=i;
        for(auto e:edges){
            int u=e[0],v=e[1];
            int uu=findp(p,u);
            int uv=findp(p,v);
            if(uu==uv)return e;
            p[uu]=uv;
        }
        return {};
    }
};