class Solution {
    pair<int, int> getCounts(string& s) {
        int zeros = 0;
        int ones = 0;
        for (auto ch : s) {
            zeros += (ch == '0');
            ones += (ch == '1');
        }
        return {zeros, ones};
    }
    int getMaxSubsetSize(int index, int zeros, int ones, vector<string>& strs,
                         vector<vector<vector<int>>>& dp,
                         vector<pair<int, int>>& countPair) {
        if (index == (int)strs.size()) {
            return 0;
        }

        if (dp[index][zeros][ones] != -1) {
            return dp[index][zeros][ones];
        }

        // dont choose
        int operation1 =
            getMaxSubsetSize(index + 1, zeros, ones, strs, dp, countPair);
        int operation2 = 0;

        // choose if possible
        if (countPair[index].first <= zeros &&
            countPair[index].second <= ones) {
            operation2 =
                1 + getMaxSubsetSize(index + 1, zeros - countPair[index].first,
                                     ones - countPair[index].second, strs, dp,
                                     countPair);
        }

        return dp[index][zeros][ones] = max(operation1, operation2);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<pair<int, int>> countPair;

        // precomputing counts
        for (auto str : strs) {
            countPair.push_back(getCounts(str));
        }
        vector<vector<vector<int>>> dp(
            size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return getMaxSubsetSize(0, m, n, strs, dp, countPair);
    }
};