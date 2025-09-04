class Solution {
public:
    string toHex(int num) {
         if(num==0){
            return "0";
        }
        unsigned int n=num;
        string hex="0123456789abcdef";
        string res="";
        while(n>0){
            int k=n & 15;
            res=hex[k]+res;
            n>>=4;
        }
        return res;
    }
};