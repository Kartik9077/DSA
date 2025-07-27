class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res=0,i=1,prev=0,next=0;
        while(i<nums.size()){
            prev=nums[i-1];
            while((i+1)<nums.size()&&nums[i+1]==nums[i]&& (i+1)<nums.size())i++;
            if(i>=nums.size()-1)return res;
            next=nums[i+1];
            if(nums[i]>prev&&nums[i]>next)res++;
            else if(nums[i]<prev&&nums[i]<next)res++;
            i++;

        }
        return res;
    }
};