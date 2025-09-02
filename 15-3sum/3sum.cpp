class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        vector<vector<int>>res;
        for(int i=0;i<n-2;i++){
            if(i!=0&&i<n&&nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)j++;
                else if(sum>0)k--;
                else{
                  ans.push_back(nums[i]);ans.push_back(nums[j]);ans.push_back(nums[k]);
                  res.push_back(ans);
                  ans.clear();j++;k--;
                  while(j<k&&nums[j]==nums[j-1])j++;
                  while(j<k&&nums[k]==nums[k+1])k--;
                }
            }
           
        }
        return res;
    }
};