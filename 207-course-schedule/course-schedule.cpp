class Solution {
public:
bool solve(vector<int>in,unordered_map<int,vector<int>>mpp,int n){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(in[i]==0)q.push(i);
    }
    int count=0;
    while(!q.empty()){
        int a=q.front();
        q.pop();
         count++; if(count>=n)return 1;
         for(auto it:mpp[a]){
            in[it]--;
            if(in[it]==0)q.push(it);
         }

    }
    return 0;
}
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int,vector<int>>mpp;
        vector<int>in(n,0);
        for(auto it:p){
            int a=it[0],b=it[1];
            mpp[b].push_back(a);
            in[a]++;
        }
        return solve(in,mpp,n);
    }
};