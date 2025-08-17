class Solution {
public:
    using ll=long long ;
    int M=1e9+7;
    ll mpow(ll a,ll e){
        ll r=1;
        a%=M;
        while(e>0){
            if(e&1) r=(r*a)%M;
            a=(a*a)%M;
            e>>=1;
        }
        return r;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int >a=nums;
        vector<vector<int> >b=queries;
        int S=max(1,(int)sqrt(nums.size()));
        vector<vector<vector<int>>>sd(S+1);
        for(int i=1;i<=S;i++){
            sd[i].resize(i);
            for(int j=0;j<i;j++){
                int m=(n-j+i-1)/i;
                if(m<0) m=0;
                sd[i][j].assign(m+1,1);
            }
        }

        for(auto &q:b){
            int l=q[0],r=q[1],k=q[2],v=q[3];
            if(k<=S){
                int rem=l%k;
                int tl=l/k;
                int tr=(r-rem)/k;
                sd[k][rem][tl]=(ll)sd[k][rem][tl]*v%M;
                int a1=(int)mpow(v,M-2);
                sd[k][rem][tr+1]=(ll)sd[k][rem][tr+1]*a1%M;
            }
            else{
                for(int i=l;i<=r;i+=k) a[i]=(ll)a[i]*v%M;
            }
        }
        for(int k=1;k<=S;k++){
            for(int rem=0;rem<k;rem++){
                int m=(n-rem+k-1)/k;
                if(m<=0) continue;
                ll pref=1;
                for(int t=0;t<m;t++){
                    pref=pref*sd[k][rem][t]%M;
                    int idx=rem+t*k;
                    if(idx<n) a[idx]=(ll)a[idx]*pref%M;
                }
            }
        }
        int total=0;
        for(auto x:a) total^=x;
        return total;
        
        
    }
};