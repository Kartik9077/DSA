class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
       unordered_set<int>st;
       for(int i=0;i<nums.size()-1;i++){
        int sum=nums[i]+nums[i+1];
        if(st.find(sum)!=st.end())return 1;
        st.insert(sum);
       }
       return 0;
    }
};