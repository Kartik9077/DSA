class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
       int t=(int)arr.size()/4;
       vector<int>nums=arr;
       int curr=1;
      for(int i=1;i<arr.size();i++){
        if(nums[i]!=nums[i-1])curr=1;
        else curr++;
        if(curr>t)return nums[i];
      }
      if(curr>t)return nums[nums.size()-1];
      return 0;
        
    }
};