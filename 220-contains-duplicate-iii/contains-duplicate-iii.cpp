class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        unordered_map<long, long> buckets;
        long w = (long)valueDiff + 1;

        for (int i = 0; i < nums.size(); i++) {
            long num = (long)nums[i];
            
            long bucketId = num / w;
            if (num < 0) bucketId--; 

            if (buckets.count(bucketId)) return true;

            if (buckets.count(bucketId - 1) && abs(num - buckets[bucketId - 1]) <= valueDiff)
                return true;
            if (buckets.count(bucketId + 1) && abs(num - buckets[bucketId + 1]) <= valueDiff)
                return true;

            buckets[bucketId] = num;

            if (i >= indexDiff) {
                long oldBucketId = (long)nums[i - indexDiff] / w;
                if (nums[i - indexDiff] < 0) oldBucketId--;
                buckets.erase(oldBucketId);
            }
        }

        return false;
    }
};