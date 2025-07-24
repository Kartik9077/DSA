class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX,maxii=INT_MIN;
        vector<int>buy(n,0),sell(n,0);
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            buy[i]=mini;
        }
        for(int j=n-1;j>=0;j--){
            maxii=max(maxii,nums[j]);
            sell[j]=maxii;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,sell[i]-buy[i]);

        }
        return ans;
    }
};