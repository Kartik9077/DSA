class Solution {
public:
  int solve(int n,int x,int y,int pos){
    if(n==0)return 1;
    if(n==1)return 10;
      if(pos>n)return x;
     y*=(10-(pos-1));
     x+=y;
     return solve(n,x,y,pos+1);
      
  }
    int countNumbersWithUniqueDigits(int n) {
       
        return solve(n,10,9,2);
        
    }
};