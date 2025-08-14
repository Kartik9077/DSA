class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
       for(int i=0;i<num.size()-2;i++){
        string k=num.substr(i,3);
         if(k[0]==k[1]&&k[1]==k[2]){
            if(k>ans)ans=k;
         }
       }
       return ans;
    }
};