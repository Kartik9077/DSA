class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        if(n==1)return 10;
        int to=10;
        int curr=9;
        for(int i=2;i<=n;i++){
        curr *= (10 - (i - 1));
        to+=curr;
        }
        return to;
        
    }
};