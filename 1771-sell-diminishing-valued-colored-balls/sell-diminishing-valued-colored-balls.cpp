class Solution {
public:
    int mod=1e9+7;

    long long func(int mid,vector<int> &nums){
        int n=nums.size();
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>=mid){
                sum+=((long long)(nums[i]-mid)+1);
            }else break;
        }
        return sum;
    }

    long long total(int mid,vector<int> &nums){
        int n=nums.size();
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            if(mid<=nums[i]){
                long long cnt=(long long)((nums[i]-mid)+1);
                
                long long add=(cnt*(long long)(nums[i]+mid))/2;
                sum+=add;
            }
            else break;
        }
        return sum;
    }


    int maxProfit(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        long long num=0;
        int ans=-1;
        int high=nums[n-1];
        while(low<=high){
            int mid=low+((high-low)/2);
            
            if(func(mid,nums)<k){
                high=mid-1;
            }
            else {
                ans=mid;
                num=func(mid,nums);
                low=mid+1;
            }
        }   
        long long extra=num-k;
        long long minus=(extra*ans*1LL)%mod;
        long long res=total(ans,nums)%mod;
        long long final=(res-minus)%mod;
        if(final<0)final+=mod;
        return (int)final;
    }
};