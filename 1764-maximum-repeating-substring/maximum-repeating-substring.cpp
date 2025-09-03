class Solution {
public:
    bool check(int k, const string& s, const string& w) {
        string repeated = "";
        for (int i = 0; i < k; i++) {
            repeated += w;
        }
        return s.find(repeated) != string::npos;
    }

    int maxRepeating(string sequence, string word) {
        int l = 0, r = sequence.size() / word.size();
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, sequence, word)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};