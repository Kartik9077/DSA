class Solution {
public:
    #define pii pair<int, int>
    int t[4*100000], n;
    void update(int idx, int tl, int tr, int pos) {
        if(tl == tr) t[idx] = 1;
        else {
            int tm = (tl + tr) / 2;
            if(pos <= tm) update(2*idx, tl, tm, pos);
            else update(2*idx + 1, tm + 1, tr, pos);
            t[idx] = t[2*idx] + t[2*idx + 1];
        }
    }
    int getsum(int idx, int tl, int tr, int l, int r) {
        if(l > r) return 0;
        else if(tl == l && tr == r) return t[idx];
        int tm = (tl + tr) / 2;
        int left = getsum(2*idx, tl, tm, l, min(tm, r)),
            right = getsum(2*idx + 1, tm + 1, tr, max(l, tm + 1), r);
        return left + right;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        memset(t, 0, sizeof(t));
        n = nums1.size();
        vector<pii> nums(n), snums;
        for(int i = 0; i < n; i++) nums[i] = {nums1[i] - nums2[i], i};
        snums = nums;
        sort(snums.begin(), snums.end());
        for(int i = 0; i < n; i++) nums[snums[i].second].second = i; 
        long long count = 0;
        if(diff > 0) {
            for(int i = n - 1; i >= 0; i--) {
                int sidx = nums[i].second;
                int start = upper_bound(snums.begin(), snums.end(), pii(snums[sidx].first - diff, 0)) - snums.begin();
                start = min(n - 1, start);
                count += (long long)getsum(1, 0, n - 1, start, n - 1);
                update(1, 0, n - 1, sidx);
            }
        } else {
            for(int i = n - 1; i >= 0; i--) {
                int sidx = nums[i].second;
                int start = lower_bound(snums.begin(), snums.end(), pii(snums[sidx].first - diff, 0)) - snums.begin();
                if(start == n) {
                    update(1, 0, n - 1, sidx);
                    continue;
                }
                count += (long long)getsum(1, 0, n - 1, start, n - 1);
                update(1, 0, n - 1, sidx);
            }
        }
        return count;
    }
};