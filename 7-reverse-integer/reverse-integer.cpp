class Solution {
public:
    int reverse(int x) {
        long  rev_num = 0;
        while(x != 0){
            rev_num *= 10;
            rev_num += x % 10;
            x /=10;
        }
        if( x < 0){
            rev_num *= -1;
        }
        if(rev_num <= INT_MAX && rev_num >= INT_MIN){
            return rev_num;
        }else{
            return 0;
        }
    }
};