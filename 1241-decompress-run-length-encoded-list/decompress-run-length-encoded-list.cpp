class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
    vector<int>ans;
      for(int i=1;i<nums.size();i+=2)
        for(int j=1;j<=nums[i-1];j++)ans.push_back(nums[i]);
      
      return ans;

    }
};