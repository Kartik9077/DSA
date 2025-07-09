class DSU {
public:
    vector<int> sze, par;
    DSU(int n) {
        sze.assign(n + 1, 1);
        par.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            par[i] = i;
    }
    int findPar(int node) {
        if (par[node] == node)
            return node;
        return par[node] = findPar(par[node]);
    }
    void unite(int u, int v) {
        int ult_u = findPar(u);
        int ult_v = findPar(v);
        if (ult_u == ult_v)
            return;
        if (sze[ult_u] < sze[ult_v]) {
            par[ult_u] = ult_v;
            sze[ult_v] += sze[ult_u];
        } else {
            par[ult_v] = ult_u;
            sze[ult_u] += sze[ult_v];
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n =s.size();
        DSU ds(n);
        for(auto it: pairs) {
            ds.unite(it[0], it[1]);
        }

        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; ++i) {
            int root =ds.findPar(i);
            mp[root].push_back(i);
        }
        string res =s;
        for(auto [root,ind]: mp) {
            string tmp ="";
            for(int i: ind) {
                tmp +=s[i];
            }
            sort(begin(tmp), end(tmp));
            sort(begin(ind), end(ind));
            for(int i=0; i<ind.size(); ++i) {
                res[ind[i]] =tmp[i];
            }
        }
        return res;
    }
};