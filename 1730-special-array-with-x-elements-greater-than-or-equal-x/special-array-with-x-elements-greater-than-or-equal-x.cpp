class Solution {
public:
int  check(int a,vector<int>nums){
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=a)count++;
    }
    return count;
}
    int specialArray(vector<int>& nums) {
         int low=0,high=nums.size();
         int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,nums)==mid){
            return mid;
            }
            else if(check(mid,nums)<mid)high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};