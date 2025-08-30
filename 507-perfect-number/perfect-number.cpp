class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=1;
        if(num==1)return 0;
        for(int i=2;i<num;i++){
            if(num%i==0)sum+=i;
        }
        return num==sum;
        
    }
};