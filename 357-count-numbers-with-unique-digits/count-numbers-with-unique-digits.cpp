class Solution {
public:
  int solve(int n,int x,int y,int pos){
      if(pos>n)return x;
     y*=(10-(pos-1));
     x+=y;
     return solve(n,x,y,pos+1);
      
  }
    int countNumbersWithUniqueDigits(int n) {
        // if(n==0)return 1;
        // if(n==1)return 10;
        // int to=10;
        // int curr=9;
        // for(int i=2;i<=n;i++){
        // curr *= (10 - (i - 1));
        // to+=curr;
        // }
        // return to;
         if(n==0)return 1;
    if(n==1)return 10;
        return solve(n,10,9,2);
        
    }
};