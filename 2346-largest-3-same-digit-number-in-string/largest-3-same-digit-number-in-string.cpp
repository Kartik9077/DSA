class Solution {
public:
 bool check(string k){
    sort(k.begin(),k.end());
    if(k[0]==k[2])return 1;
    return 0;
 }
    string largestGoodInteger(string num) {
        string ans="";
       for(int i=0;i<num.size()-2;i++){
        string k=num.substr(i,3);
        if(check(k)){
            if(k>ans)ans=k;
        }
       }
       return ans;
    }
};