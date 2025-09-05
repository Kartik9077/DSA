class Solution {
    static const bool comp(pair<int,int>a,pair<int,int>b){
        if(a.second==b.second)return a.first<b.first;
        return a.second<b.second;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>a;
        for(int i=0;i<mat.size();i++)
        { int co=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)co++;
                else break; 
            }
            a.push_back({i,co});
        }
        sort(a.begin(),a.end(),comp);
        vector<int>ka;
        for(auto it:a){
            ka.push_back(it.first);
        }
        ka.resize(k);
        return ka;
    }
};