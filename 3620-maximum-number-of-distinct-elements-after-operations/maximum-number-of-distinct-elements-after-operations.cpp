class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long last = LLONG_MIN;
        int cnt = 0;

        for (int i = 0;i<nums.size();i++) {
            long long pick = max((long long)nums[i] - k, last + 1);
            if (pick <= (long long)nums[i] + k) {
                cnt++;
                last = pick;
            }
        }

        return cnt;
    }
};