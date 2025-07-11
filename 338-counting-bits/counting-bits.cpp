class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>arr(n+1);
        for(int i=0;i<=n;i++){
            arr[i]=__builtin_popcount(i);

        }
        return arr;
        
    }
};