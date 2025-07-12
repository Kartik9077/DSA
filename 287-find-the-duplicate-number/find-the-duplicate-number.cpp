class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]^nums[i+1])continue;
            else return nums[i];
        }
        
        // int n=nums.size();
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]^nums[j])continue;
        //         else return nums[i];
        //     }
        // }
    return -1;
        
    }
};