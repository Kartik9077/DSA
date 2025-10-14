class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>postfix(n,1);
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
               postfix[i]=postfix[i+1]+1;

            int a=i,b=a+k;
            if(postfix[a]>=k && b<n && postfix[b]>=k)
               return true;   
        }
        return false;
    }
};