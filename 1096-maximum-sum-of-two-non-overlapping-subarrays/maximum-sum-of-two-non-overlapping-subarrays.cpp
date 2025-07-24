class Solution {
public:
int cal(vector<int>&nums,int f,int s){
    int n=nums.size(),sum=0;
    vector<int>dp(n,0),sp(n,0);
    for(int i=0;i<n;i++){
        if(i<f){
            sum+=nums[i];
            dp[i]=sum;
        }
        else{
            sum=sum+nums[i]-nums[i-f];
            dp[i]=max(sum,dp[i-1]);
        }
    }
    sum=0;
    for(int j=n-1;j>=0;j--){
        if(j+s>n-1){
            sum+=nums[j];
            sp[j]=sum;
        }
        else
        {
            sum=sum+nums[j]-nums[j+s];
            sp[j]=max(sum,sp[j+1]);
        }
    }
    int res=0;
    for(int i=f-1;i<n-s;i++){
        res=max(res,dp[i]+sp[i+1]);

    }
    return res;
}
    int maxSumTwoNoOverlap(vector<int>& nums, int fir, int sec) {
    return max(cal(nums,fir,sec),cal(nums,sec,fir));
        
    }
};