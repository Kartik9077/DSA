class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int sum=accumulate(nums.begin(),nums.end(),0);
        return (sum-mini*n);

    }
};