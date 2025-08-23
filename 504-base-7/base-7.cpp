class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)return "0";
        string ans="";bool k=0;
        if(num<0){num*=-1;k=1;}
        string x="";
        while(num>0){
            int rem=num%7;
            string x=to_string(rem);
            x+=ans;
            ans=x;
            num=num/7;
        }
    
        if(k==1){
            x="-";
            x+=ans;
            ans=x;
        }
        return ans;
        
    }
};