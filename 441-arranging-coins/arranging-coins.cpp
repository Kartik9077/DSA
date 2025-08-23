class Solution {
public:
    int arrangeCoins(int n) {
        int row=0;
        while(n>=row+1){
            row++;
            n-=row;
        }
        return row;
        
    }
};