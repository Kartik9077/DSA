class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;
        int ans = 0;

        for (int third = 0; third <= 9; third += 2) {
            if (freq[third] == 0) continue;
            freq[third]--;
            for (int second = 0; second <= 9; second++) {
                if (freq[second] == 0) continue;
                freq[second]--;
                for (int first = 1; first <= 9; first++) {
                    if (freq[first] > 0) {
                        ans++;
                    }
                }
                freq[second]++;
            }
            freq[third]++;
        }

        return ans;

    }
};