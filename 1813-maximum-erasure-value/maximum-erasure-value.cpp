class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0,i=0,j=0,curr=0;
        unordered_set<int>st;
        while(i<nums.size()){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                curr+=nums[i];
                i++;
            }
            else{
                ans=max(ans,curr);
                while(st.find(nums[i])!=st.end()&&j<i){
                    curr-=nums[j];
                    st.erase(nums[j]);j++;
                }
            }
        }
        ans=max(ans,curr);
        return ans;
    }
};