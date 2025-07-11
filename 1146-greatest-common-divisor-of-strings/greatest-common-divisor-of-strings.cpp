class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
       if(str1+str2 != str2+str1)return "";
        
        auto gcd=[](int a,int b){
while(b!=0){
int temp=a%b;
a=b;
b=temp;}
            return a;
            
            };
        int lengcd=gcd(str1.length(),str2.length());
        return str1.substr(0,lengcd);
    }
};