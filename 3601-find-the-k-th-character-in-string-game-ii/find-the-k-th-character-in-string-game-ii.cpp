class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long idx =10, sum = 0;
        while(k>1){
            idx = log2(k);
            if((1LL<<idx) == k) idx--;
            k %= (1LL<<idx);
            if(k ==0) k+= (1LL<<idx);
            if(operations[idx] == 1){
                sum++;
            }
        }
        return 'a' + sum%26;
    }
};