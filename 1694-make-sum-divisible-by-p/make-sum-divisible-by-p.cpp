class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (int num : nums)
            sum = (sum + num) % p;

        int k = sum % p;
        if (k == 0) return 0;

        return minimumSubArraySumEqualsK(nums, k, p);
    }

    int minimumSubArraySumEqualsK(vector<int>& nums, int k, int p) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        int minLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % p;

            int remain = (sum - k + p) % p;

            if (mp.count(remain)) {
                minLen = min(minLen, i - mp[remain]);
            }

            mp[sum] = i;
        }

        if (minLen == n) return -1;
        return minLen == INT_MAX ? -1 : minLen;
    }
};