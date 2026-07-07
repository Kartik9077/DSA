class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        long long sum=0;
        stack<int>st;
        while(n>0){
            int x=n%10;
            if(x!=0)st.push(x);
            sum+=x;
            n/=10;
        }
        while(!st.empty()){ans*=10;ans+=st.top();st.pop();}
        ans=ans*sum;
        return ans;
    }
};