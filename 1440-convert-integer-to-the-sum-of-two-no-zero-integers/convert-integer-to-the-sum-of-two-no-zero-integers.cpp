class Solution {
public:
bool check( int a){
    while(a>0){
        if((a%10)==0)return 0;
        a/=10;
    }
    return 1;
}
    vector<int> getNoZeroIntegers(int n) {
        int a=0,b=0;
        for(int i=1;i<n;i++){
            a=i,b=n-i;
            if(check(a)&&check(b))return {a,b};
        }
        return {0};
    }
};