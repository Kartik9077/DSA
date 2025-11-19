class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
         int maxii=*max_element(nums.begin(),nums.end());
         unordered_set<int>st;
         for(auto it:nums)st.insert(it);
         while(original<=maxii){
            if(st.find(original)==st.end())return original;
            original*=2;
         }
         return original;
    }
};