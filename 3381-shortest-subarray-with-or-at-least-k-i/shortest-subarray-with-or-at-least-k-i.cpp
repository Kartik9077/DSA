class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> cnt(32, 0);
        int res = INT_MAX, orsum = 0, i = 0, j = 0, tmp = 0;

        while(i < nums.size()){
            if(orsum < k){
                orsum |= nums[i];
                tmp = nums[i];
                for(int k = 0; k < 32; ++k){
                    cnt[k] += tmp % 2 == 1;
                    tmp /= 2;
                }
            }
            while(j <= i && orsum >= k){
                res = min(res, i - j + 1);
                int val = 0;
                tmp = nums[j];
                for(int k = 0; k < 32; ++k){
                    cnt[k] -= tmp % 2 == 1;
                    tmp /= 2;
                    if(cnt[k]) val |= 1 << k;
                }
                orsum = val;
                j++;
            }
            ++i;
        }
        return res == INT_MAX ? -1 : res;
    }
};