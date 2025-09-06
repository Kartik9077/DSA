class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
     map<int,int>mpp;
        for(auto ti:nums){
            if(ti&1)continue;
            else mpp[ti]++;
        }
        int ans=-1,maxii=0;
        for(auto it:mpp){
            if(it.second>maxii){
                maxii=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};