class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& p) {
      unordered_map<int,vector<int>>mpp;
      vector<int>in(num,0);
      for(auto it:p){
        mpp[it[1]].push_back(it[0]);
        in[it[0]]++;
      }
      queue<int>q;
      for(int i=0;i<num;i++){
        if(in[i]==0)q.push(i);
      }
      vector<int>ans;
      while(!q.empty()){
        int a=q.front();
        q.pop();
        ans.push_back(a);
        for(auto it:mpp[a]){
            in[it]-=1;
            if(in[it]==0)q.push(it);
        }
      }
      if(ans.size()==num)return ans;
      return {};
      


    }
};