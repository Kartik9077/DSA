class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)return 0;
        int ans=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int k=n-1;
                while((nums[i]+nums[j])<=nums[k]&&k>j)k--;
                
                ans+=k-j;
            }
        }
        return ans;
    }
};