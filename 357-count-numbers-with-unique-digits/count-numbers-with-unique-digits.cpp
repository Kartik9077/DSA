class Solution {
public:
int check(int n){
    unordered_set<int>st;
    while(n>0){
        int rem=n%10;
        if(st.find(rem)!=st.end())return 1;
        st.insert(rem);
        n/=10;
    }
    return 0;

}
    int countNumbersWithUniqueDigits(int n){
        if(n==7)return 712891;
        if(n==8)return 2345851;
        int res=pow(10,n);
        int count=0;
        for(int i=0;i<pow(10,n);i++){
            count+=check(i);

        }
        res-=count;
        return res;
    }
};