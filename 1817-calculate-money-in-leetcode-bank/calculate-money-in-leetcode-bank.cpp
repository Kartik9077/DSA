class Solution {
public:
    int totalMoney(int n) {
      int k=n/7;int p=28;
      int maxi=k,ans=0;
      while(k--){
        ans+=p;p+=7;
      }
      n%=7;
      while(n--){
        ans+=maxi+1;
        maxi++;
      }
      return ans;

    }
};