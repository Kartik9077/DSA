class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int i=0,j=0,curr=0,ans=0,count=0;
        while(i<nums.size()){
            if(nums[i]==1){
                curr++;i++;
            }
            else if(nums[i]==0&&count<k){
                count++;
                curr++;
                i++;
            }
            else
            {
                ans=max(curr,ans);
                while(count==k){
                    if(nums[j]==0)count--;
                    curr--;j++;
                }
                curr++;
                count++;
                i++;
            }
        }
        ans=max(ans,curr);
        return ans;

        
    }
};