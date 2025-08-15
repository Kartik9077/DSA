class Solution {
public:
    bool isPowerOfFour(int num) {

        if(num==1)return 1;
        double n=(double)num;
        while(n>=4){
            if(n==4)return 1;
            n/=4;
        }
        return 0;
    }
};