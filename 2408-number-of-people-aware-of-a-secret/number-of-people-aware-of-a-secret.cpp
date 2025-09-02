class Solution {
public:
    const int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int curr = 0; 
        int ans = 1; 
        queue<pair<int, int>> forgetQ, delayQ;
        forgetQ.push({1, 1});
        delayQ.push({1, 1});

        for (int i = 1; i <= n; i++) {
            if (!forgetQ.empty() && forgetQ.front().first + forget <= i) {
                auto front = forgetQ.front();
                forgetQ.pop();
                curr = (curr - front.second + mod) % mod;
                ans = (ans - front.second + mod) % mod;
            }
            if (!delayQ.empty() && delayQ.front().first + delay <= i) {
                auto front = delayQ.front();
                delayQ.pop();
                curr = (curr + front.second) % mod;
            }
            if (curr > 0) {
                ans = (ans + curr) % mod;
                forgetQ.push({i, curr});
                delayQ.push({i, curr});
            }
        }
        return ans;
    }
};