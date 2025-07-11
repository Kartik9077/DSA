class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),i=0;
        while(i<n&&nums[i]!=0)i++;
        if(i>=n-1)return;
        int k=i+1;
        while(k<n){
            if(nums[k]!=0)swap(nums[i++],nums[k++]);
            else k++;
        }
    }
};