class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        unordered_map<int,int>mpp;int ans=0;
     for(int i=1;i<nums.size()-2;i++){
        for(int j=0;j<i;j++){
            int sum=nums[i]+nums[j];
            if(sum<101)mpp[sum]++;

        }
        int c=nums[i+1];
        for(int d=i+2;d<nums.size();d++){
            int diff=nums[d]-c;
            if(diff>=0)ans+=mpp[diff];
        }
     }
     return ans;

    }
};