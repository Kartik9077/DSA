class Solution {
public:
    int arrayNesting(vector<int>& nums) {
       int ans=0;unordered_set<int>st;
        for(int a=0;a<nums.size();a++){
            if(st.find(a)!=st.end())continue; 
            int c=0;
        while(st.find(nums[a])==st.end()){
            c+=1;
            st.insert(nums[a]);
            a=nums[a];
        }
        ans=max(ans,c);
        }
        return ans;
    }
};