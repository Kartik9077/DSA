class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
    int n=nums.size(),res=0;
    for(int i=1,c=1,p=0;i<n;i++){
        if(nums[i]>nums[i-1])++c;
        else{
            p=c,c=1;
        }
        res=max({res,min(p,c),c>>1});}

    return res;
    }
};