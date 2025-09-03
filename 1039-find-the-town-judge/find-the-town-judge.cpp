class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
          vector<bool> outgoing(n+1, false); vector<int> trustCount(n+1, 0);
        for(auto&i:trust){
            outgoing[i[0]] = 1; trustCount[i[1]] += 1;
        }
        for(int i=1; i<=n; i++) if(!outgoing[i] && trustCount[i]==n-1) return i;
        return -1;
    }
};