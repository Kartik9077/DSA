class Solution {
public:
    int countOdds(int low, int high) {
        if(high==low&&high&1)return 1;
        else if(high==low&& !(high&1))return 0;
      if(low&1&&high&1)return 2+(high-low-1)/2;
      if(!(low&1)&&!(high&1))return (high-low)/2;
      else return 1+(high-low)/2;

    }
};