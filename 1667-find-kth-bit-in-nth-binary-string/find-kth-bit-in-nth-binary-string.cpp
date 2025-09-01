class Solution {
public:
    int length(int n){
        return (1<<n) - 1;
    }
    char findKthBit(int n, int k) {
        if(n==1)return '0';
         int mid = (1 << (n - 1)); 
        if (k == mid) return '1'; 
        if(k<mid){
            return findKthBit(n-1,k);
        }
        char inverted = findKthBit(n-1,length(n)-k+1);
        if(inverted=='0')return '1';
        return '0';
    }
};