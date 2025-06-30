class Solution {
public:
typedef long long ll;
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        vector<int>ans;
        sort(a.begin(),a.end());sort(b.begin(),b.end());
        ll n=accumulate(a.begin(),a.end(),0);
        ll m=accumulate(b.begin(),b.end(),0);
        int k=1;
        if(n>m)k=0;
        ll diff=abs(n-m);
         diff/=2;
         for(auto it:a){
            for(auto t:b){
                if(k==0){
                if(it-t==diff)return {it,t};
                }
                else{
                    if(t-it==diff)return {it,t};
                }
            }
         }
        return ans;
    }
};