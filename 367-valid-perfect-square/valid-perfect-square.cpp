class Solution {
public:
    bool isPerfectSquare(int num) {
        int n=sqrt(num);
        if((n*n)==num)return 1;
        return 0;
    }
};