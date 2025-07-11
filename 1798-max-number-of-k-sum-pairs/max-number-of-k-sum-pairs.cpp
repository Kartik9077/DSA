class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());int ans=0;
        int r=0,l=nums.size()-1;
        while(r<l){
            if(nums[r]+nums[l] <k)r++;
            else if(nums[r]+nums[l] >k)l--;
            else{
                ans++;
                l--;r++;

            }
        }
        return ans;
        
    }
};