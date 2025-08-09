class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)return 1;
        long long nu=2;
        while(nu<=n){if(n==nu)return 1;nu*=2;}
        return 0;
    }
};