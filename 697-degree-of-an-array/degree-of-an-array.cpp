class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
       unordered_map<int,vector<int>>mpp;
      for(int i=0;i<nums.size();i++)mpp[nums[i]].push_back(i);
      int maxii=0;
      for(auto&[a,b]:mpp)maxii=max(maxii,(int)b.size());
      int ans=INT_MAX;
     for(auto &[a,b]:mpp){
        if(b.size()<maxii)continue;
        else{
            int i=0,j=i+maxii-1;
            while(j<b.size()){
                ans=min(ans,b[j]-b[i]+1);
                j++;i++;
            }
        }
     }
     return ans;
        

    }
};