class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
         int n = arr.size();
        if (n < 2) return n;
        int inc = 1, dec = 1, maxLen = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                inc = dec + 1;
                dec = 1;
            } 
            else if (arr[i] < arr[i - 1]) {
                dec = inc + 1;
                inc = 1;
            } 
            else inc = dec = 1;
            maxLen = max(maxLen, max(inc, dec));
        }
        return maxLen;
    }
};