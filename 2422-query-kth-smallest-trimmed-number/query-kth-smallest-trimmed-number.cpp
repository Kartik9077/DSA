class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int m = nums[0].size();

        vector<int> ordnums(n);
        std::iota(ordnums.begin(), ordnums.end(), 0);

        vector<int> ord(q);
        std::iota(ord.begin(), ord.end(), 0);
        std::sort(ord.begin(), ord.end(), [&](int i, int j) { return queries[i][1] < queries[j][1]; });

        int pass = 0;
        auto bucket_sort = [&]() -> vector<int> {
            vector<int> count(10, 0);
            for (auto i: ordnums) {
                int d = (nums[i][m - 1 - pass] - '0');
                count[d]++;
            }
            vector<int> idx(10, 0);
            for (int i= 1; i < 10; i++) {
                count[i] += count[i - 1];
                idx[i] = count[i - 1];
            }
            vector<int> output(n);
            for (auto i: ordnums) {
                int d= (nums[i][m - 1 - pass] - '0');
                output[idx[d]++] = i;
            }

            return output;
        }; 

        vector<int> ans(q);
        for (auto i: ord) {
            while (pass < queries[i][1]) {
                ordnums = bucket_sort();
                ++pass;
            }
            
            ans[i] = ordnums[queries[i][0] - 1];
        }

        return ans;
    }
};