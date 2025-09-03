class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int ct = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]) ct++;
            else ct = 1;
            if(ct == nums.size()/2) return nums[i];
        }
        return 0;
    }
};