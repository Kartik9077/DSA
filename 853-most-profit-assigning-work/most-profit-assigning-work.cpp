class Solution {
public:
static bool comp(pair<int,int>&a,pair<int,int>&b){
return a.first<b.first;
}
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>check;
        for(int i=0;i<profit.size();i++){
            check.push_back({difficulty[i],profit[i]});
        }
        sort(check.begin(),check.end(),comp);
        int ans=0;
        for(int i=0;i<worker.size();i++){
            int curr=0;
            for(int j=0;j<check.size();j++){
                if(check[j].first<=worker[i]){
                    curr=max(curr,check[j].second);
                }
                else break;
            }
            ans+=curr;

        }
        return ans;
    }
};