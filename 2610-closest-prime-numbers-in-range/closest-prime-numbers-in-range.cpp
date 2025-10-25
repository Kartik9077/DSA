class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right <= 2) return {-1, -1};
        
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (long long i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (long long j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        int prevPrime = -1;
        int minDistance = INT_MAX;
        vector<int> result = {-1, -1};
        
        for (int i = max(2, left); i <= right; i++) {
            if (isPrime[i]) {
                if (prevPrime != -1) {
                    int distance = i - prevPrime;
                    if (distance < minDistance) {
                        minDistance = distance;
                        result[0] = prevPrime;
                        result[1] = i;
                        if (distance == 2) break;
                    }
                }
                prevPrime = i;
            }
        }
        
        return result;
    }
};