class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int>prime;
        vector<int>isprime(1001,1);
        for(int i=2;i<=1000;i++){
            if(isprime[i]==0) continue;
            for(int j=i*i;j<=1000;j=j+i){
                isprime[j] = 0;
            }
        }
        for(int i=2;i<=1000;i++){
            if(isprime[i]==1) prime.push_back(i);
        }
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<prime.size();j++){
                if(prime[j]>nums[i]) break;
                if(nums[i]%prime[j]==0) s.insert(prime[j]);
            }
        }
        return s.size();
    }
};