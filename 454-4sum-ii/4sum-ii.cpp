class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>mpp;
        for(auto it:nums3)
        for(auto ti:nums4){
            __int128 sum=it+ti;
            mpp[sum]++;
        }

        int ans=0;
        for(auto it:nums1){
            for(auto ti:nums2){
                __int128 k=-1*(it+ti);
                if(mpp.find(k)!=mpp.end())ans+=mpp[k];
            }
        }
        return ans;
    }
};