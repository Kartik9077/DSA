class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int start=0,end=0,ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])continue;
        if(nums[i]!=nums[i-1]+1){
            ans=max(ans,end-start+1);
            start=i;end=i;
        }
        else end++;
        }
        ans=max(end-start+1,ans);
        return ans;
    }
};