class Solution {
public:
     int check(int a,int b){
          while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
     }
    bool hasGroupsSizeX(vector<int>& d) {
        int res=0;
      unordered_map<int,int>mpp;
      for(auto it:d)mpp[it]++;
      for(auto &[a,b]:mpp)res=check(res,b);
      return res>1;
    }
};