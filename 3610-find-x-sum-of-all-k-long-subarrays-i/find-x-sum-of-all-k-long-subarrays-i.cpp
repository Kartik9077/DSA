class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>v;
        for(int i=0;i<nums.size()-k+1;i++){
            int sum=0;
            unordered_map<int,int>cnt;
            vector<pair<int,int>>p;
            for(int j=i;j<=i+k-1;j++){
                if(j<nums.size()) cnt[nums[j]]++;
            }
            for(auto u:cnt){
                p.push_back({u.second,u.first});
            }
            sort(p.rbegin(),p.rend());
            int k=0;
            if(p.size()<x){
                for(auto u:p){
                    sum+=(u.first*u.second);
                }
                v.push_back(sum);
                continue;
            }
            for(int j=1;j<=x;j++){
                sum+=(p[k].second*p[k].first);
                k++;
            }
            if(sum!=0) v.push_back(sum);
        }
        return v;
    }
};