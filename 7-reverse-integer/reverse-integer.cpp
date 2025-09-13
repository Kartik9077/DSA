class Solution {
public:
    int reverse(int x) {
        __int128 rev=0;
        while(x!=0){
            int k=x%10;
            rev*=10;
            rev+=k;
            x/=10;
        }
        if(x<0)rev*=-1;
        if(rev>=INT_MIN&&rev<=INT_MAX)return (int)rev;
        return 0;
    }
};