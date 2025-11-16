class Solution {
public:
    int numSub(string s) {
          int count=0,ans=0;
          int mod=1e9+7;
          for(auto it:s){
            if(it=='1')count++;
            else count=0;
            ans%=mod;
            ans+=count;

          }
          return ans;
    }
};