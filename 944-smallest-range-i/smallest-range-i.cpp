class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
       int n=nums[0],m=nums[nums.size()-1];
         if(m-n- 2*k<=0)return 0;
         return (m-n- 2*k);
    
    }
};