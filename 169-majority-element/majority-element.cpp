class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int c=0,num=nums[0];
        // for(auto it:nums){
        //     if(it==num)c++;
        //     else c--;
        //     if(c<0){num=it;c=1;}

        // }
        // int k=0;
        // for(auto it:nums){
        //     if(it==num)k++;
        // }
        // if(k>nums.size()/2)return num;
        // return 0;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int num=-1,c=0;
        for(auto it:mpp){
            if(it.second>c){
                c=it.second;num=it.first;
            }

        }
        if(c>nums.size()/2)return num;
        return 0;


    }
};