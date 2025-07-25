class Solution {
public:
    int maxSum(vector<int>& nums) {  
        int sum=0;
        unordered_set<int>st;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(sum<0)sum=0;
            if(st.find(nums[i])==st.end()){
                if(nums[i]<0&&nums[i]<ans)continue;
                sum+=nums[i];
                ans=max(ans,sum);
            }
            st.insert(nums[i]);
        }
        return ans;
    }
};