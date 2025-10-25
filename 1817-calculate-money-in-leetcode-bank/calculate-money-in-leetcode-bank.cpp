class Solution {
public:
    int totalMoney(int n) {
      int k=n/7,p=28,maxi=k,ans=0;n%=7;
      while(k--){
        ans+=p;p+=7;
      }
      while(n--){
        ans+=maxi+1;
        maxi++;
      }
      return ans;

    }
};