class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
         sort(p.begin(), p.end(), [](const vector<int> &p1, const vector<int> &p2) {
            if (p1[0] != p2[0]) {
                return p1[0] < p2[0];
            } else {
                return p1[1] > p2[1];
            }
        });

        int ans = 0;
        for (int i = 0; i < p.size(); i++) {
            int ylimit = INT_MAX;
            for (int j = i-1; j >= 0; j --) {
                if (p[j][1] >= p[i][1] && p[j][1] < ylimit) {
                    ans += 1;
                    ylimit = min(ylimit, p[j][1]);
                }
            }
        }

        return ans;
    }
};