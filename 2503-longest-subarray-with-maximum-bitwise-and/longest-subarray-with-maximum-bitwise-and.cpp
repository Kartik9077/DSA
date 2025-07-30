class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        int maxii=0,curr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n)curr++;
            else {
                maxii=max(maxii,curr);
                curr=0;
            }
        }
        maxii=max(maxii,curr);
        return maxii;
    }
};