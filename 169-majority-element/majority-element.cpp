class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,num=nums[0];
        for(auto it:nums){
            if(it==num)c++;
            else c--;
            if(c<0){num=it;c=1;}

        }
        int k=0;
        for(auto it:nums){
            if(it==num)k++;
        }
        if(k>nums.size()/2)return num;
        return 0;

    }
};