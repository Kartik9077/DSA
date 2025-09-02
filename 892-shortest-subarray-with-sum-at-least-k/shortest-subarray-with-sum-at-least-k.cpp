class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int head=-1,tail=0;
       long long sum=0;
       int n=nums.size();
    int ans=n+1;
        while(tail<n){
                 while(head+1<n && (sum + nums[head+1]>0 && (sum <k) )){
                    head++;
                    sum+=nums[head];}
                 if (sum>=k)ans=min(ans,head-tail+1);


                 if (tail>head){
                    tail++;
                    head=tail-1;
                 }

                 else{
                    sum-=nums[tail];
                   if (nums[tail]<0) {head=tail;sum=0;}
                    tail++;
                 }
        }
        if (ans>n) return -1;

        return ans;

    }
};