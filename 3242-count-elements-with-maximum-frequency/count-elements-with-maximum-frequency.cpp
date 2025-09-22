class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums)mpp[it]++;
        int ans=0,curr=0;
        for(auto it:mpp){
            if(it.second>=curr){
                if(it.second==curr)ans+=it.second;
                else {
                    curr=it.second;
                    ans=it.second;
                }
            }
        }
        return ans;
    }
};