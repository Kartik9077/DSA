class Solution {
public:
  int mul(string a,string b){
    int aa=stoi(a),bb=stoi(b);
    return (int)aa*bb;
  }
    string complexNumberMultiply(string num1, string num2) {
        string ans="";
        string a,b,c,d;
        for(int i=0;i<num1.size();i++){
            if(num1[i]!='+')continue;
            else{
                a=num1.substr(0,i);
                b=num1.substr(i+1);
                b.pop_back();
            }
        }
        for(int i=0;i<num2.size();i++){
            if(num2[i]!='+')continue;
            else{
                c=num2.substr(0,i);
                d=num2.substr(i+1);
                d.pop_back();
            }
        }
        int p=mul(a,c),l=mul(a,d),m=mul(b,c),n=mul(b,d);
        ans+=to_string(p+(-1)*n);
        ans+='+';
        ans+=to_string(l+m);
        ans+='i';
        return ans;
    
    }


};