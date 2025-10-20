class Solution {
public:
    string smallestGoodBase(string n_str) {
         unsigned long long n = stoull(n_str);
        int max_m = log2(n + 1);
        for (int m = max_m; m >= 2; --m) {
            unsigned long long left = 2, right = pow(n, 1.0/(m-1)) + 1;
            while (left <= right) {
                unsigned long long k = left + (right - left) / 2;
                unsigned long long sum = 1, curr = 1;
                for (int i = 1; i < m; ++i) {
                    if (curr > n / k) { 
                        sum = n + 1;
                        break;
                    }
                    curr *= k;
                    sum += curr;
                }
                if (sum == n)
                    return to_string(k);
                else if (sum < n)
                    left = k + 1;
                else
                    right = k - 1;
            }
        }
        return to_string(n - 1);
    }
};