class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==3)return 0;
        __int128 low=0,high=sqrt(c);
        while(low<=high){
            __int128 sum=low*low+high*high;
            if(sum==c)return 1;
            if(sum>c)high--;
            else low++; 
        }
        return 0;
    }
};