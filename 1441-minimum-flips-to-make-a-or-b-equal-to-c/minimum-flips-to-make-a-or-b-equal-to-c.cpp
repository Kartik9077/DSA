class Solution {
public:
    int minFlips(int a, int b, int c) {
        int f=0;
        while(a!=0||b!=0||c!=0){
            int a_bit=a&1,b_bit=b&1,c_bit=c&1; 
            if((a_bit|b_bit)!=c_bit){ 
                if(c_bit==1)f+=1; 
                else f+=(a_bit+b_bit); 
            } 
        
        a>>=1;
        b>>=1;c>>=1;}
        return f;
        
    }
};
