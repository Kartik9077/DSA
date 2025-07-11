class Solution {
public:
    string mergeAlternately(string a, string b) {
       string x="";int n=a.size(),m=b.size();
       int p=min(n,m);int i=0;
        while(i<p){
        x+=a[i];
        x+=b[i++];
       }
       while(i<a.size())x+=a[i++];
       while(i<b.size())x+=b[i++];
       return x;

       

    }
};