class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxii=INT_MIN;
        int j=0;
        while(j<nums.size()){
            maxii=max(maxii,nums[j]);
            if(nums[j]<0)j++;
            else break;
        }
        if(j==nums.size())return maxii;
        int sum=0;
        unordered_set<int>st;
        for(auto it:nums){
            if(st.find(it)==st.end() && it>=1)sum+=it;
            st.insert(it);
        }
        return sum;
    }
};