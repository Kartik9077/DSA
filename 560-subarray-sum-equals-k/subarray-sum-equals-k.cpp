class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,count=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int required=sum-k;
            if(mpp.find(required)!=mpp.end()){
                count+=mpp[required];

            }
            mpp[sum]++;

        }
        return count;
    }
};