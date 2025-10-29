class Solution {
public:
    int countValidSelections(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> prefix(n,0),suffix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;++i) prefix[i]=prefix[i-1]+nums[i];
        suffix[n-1]=nums[n-1]; 
        for(int i=n-2;i>=0;--i) suffix[i]=suffix[i+1]+nums[i];
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==0)
            {
                if(suffix[i]==prefix[i]) cnt+=2;
                else if(suffix[i]+1==prefix[i] or prefix[i]+1==suffix[i]) cnt++;
            }
        }
        return cnt;
    }
};