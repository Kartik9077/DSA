static bool comp(vector<int>&a,vector<int>&b){
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>>ans;
       sort(in.begin(),in.end(),comp);
       vector<int>prev=in[0];
       for(int i=0;i<in.size();i++){
          vector<int>curr=in[i];
          if(prev[1]>=curr[0]){
            prev[1]=max(prev[1],curr[1]);

          }
          else{
            ans.push_back(prev);
            prev=curr;
          }
       }
       ans.push_back(prev);
       return ans;
        
    }
};