class Solution {
public:
    int mod = 1e9 + 7;
    using ll = long long;
    ll expo(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> prime(100001, true);
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= 100000; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= 100000; i += p)
                    prime[i] = false;
            }
        }
        vector<int> primeScore(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int cnt = 0;
            for (int p = 2; p * p <= num; ++p) {
                if (prime[p] && num % p == 0) {
                    cnt++;
                    while (num % p == 0)
                        num /= p;
                }
            }
            if (num > 1) cnt++;
            primeScore[i] = cnt;
        }
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && primeScore[st.top()] < primeScore[i])
                st.pop();
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && primeScore[st.top()] <= primeScore[i])
                st.pop();
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }
        vector<ll> freq(n);
        for (int i = 0; i < n; ++i) {
            freq[i] = 1LL * (i - left[i]) * (right[i] - i);
        }
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] > nums[b];
        });
        ll score = 1;
        for (int i : idx) {
            ll use = min(freq[i], (ll)k);
            score = score * expo(nums[i], use) % mod;
            k -= use;
            if (k == 0) break;
        }
        return score;
    }
};