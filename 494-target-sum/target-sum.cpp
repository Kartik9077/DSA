class Solution {
public:
    int solve(vector<int>&nums,int tar, int n){
        vector<int>prev(tar+1,0),cur(tar+1,0);
        if(nums[0]==0)prev[0]=2;
        else prev[0]=1;
        if(nums[0]!=0&&nums[0]<=tar)prev[nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                int np=prev[j];
                int p=0;
                if(nums[i]<=j){
                    p=prev[j-nums[i]];
                }
                cur[j]=np+p;
            }
            prev=cur;
        }
        return prev[tar];
    }

    int countsubset(vector<int>&nums,int tar){
        int n=nums.size();
        int ts=0;
        for(int n:nums) ts+=n;
        if(ts-tar<0||((ts-tar))%2!=0) return 0;
        return solve(nums,(ts-tar)/2,n);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countsubset(nums,target);
    }
};