class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;int max_count=0,ele=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=mpp[nums[i]]+1;
            if(mpp[nums[i]]>max_count){
                max_count=mpp[nums[i]];ele=nums[i];
            }
        }
        if(max_count>nums.size()/2)return ele;
        return -1;
    }
};