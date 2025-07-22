class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=1e5+1;
        vector<int>check(n,0);
        for(auto it:nums)check[it]+=it;

        int take=0,skip=0;
        for(int i=0;i<n;i++){
            int takei=skip+check[i];
            int skipi=max(skip,take);
            take=takei;skip=skipi;
        }return max(take,skip);
    }
};