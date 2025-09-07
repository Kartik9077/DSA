class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3){
        unordered_map<int,int>mpp,mpp2;
        for(auto it:nums1){if(mpp.find(it)==mpp.end())mpp[it]++; }
        for(auto it:nums2){
          if(mpp2.find(it)==mpp2.end())mpp2[it]++;

        }
        for(auto it:mpp2)mpp[it.first]++;
        for(auto it:nums3){
            if(mpp.count(it)>=1)mpp[it]++;
        }
        vector<int>ans;
        for(auto it:mpp){
            if(it.second>=2)ans.push_back(it.first);
        }
        return ans;

 }
};