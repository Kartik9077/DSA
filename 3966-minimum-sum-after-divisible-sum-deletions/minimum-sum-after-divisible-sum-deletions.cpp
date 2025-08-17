class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
         int n = nums.size();
        const long long INF = (long long)9e18;
        vector<long long> best(k, INF);
        best[0] = 0;
        long long pref = 0;
        long long prev = 0;
        for (int i = 1; i <= n; ++i) {
            pref = (pref + nums[i-1]) % k;
            if (pref < 0) pref += k;
            long long cur = min(prev + nums[i-1], best[pref]);
            best[pref] = min(best[pref], cur);
            prev = cur;
        }
        return prev;
    }
};